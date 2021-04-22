/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvader <tvader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:25:54 by tvader            #+#    #+#             */
/*   Updated: 2021/04/22 14:00:08 by tvader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		endi;
	char	*res;

	endi = 0;
	while (ft_isinset(*s1, set) && *s1)
		s1++;
	while (*(s1 + endi))
		endi++;
	while ((ft_isinset(*(s1 + endi), set) || !(*(s1 + endi))) && endi)
		endi--;
	res = (char *)malloc(sizeof(char) * (endi + 1));
	res[endi + 1] = 0;
	while (endi >= 0)
	{
		res[endi] = s1[endi];
		endi--;
	}
	return (res);
}