/*	$NetBSD: ealloc.h,v 1.1.1.1 2004/08/27 01:49:16 schmonz Exp $	*/

void	*emalloc(size_t);
char	*estrdup(const char *);
void	*erealloc(void *, size_t);
void	*ecalloc(size_t, size_t);
