# $NetBSD: Makefile,v 1.1 2020/05/24 16:44:20 nat Exp $

PROG=  diffbreaker
MAN=   diffbreaker.1
DPADD=	${LIBCURSES} ${LIBTERMINFO}
LDADD=	-lcurses -lterminfo

WARNS?=	6
.include <bsd.prog.mk>
