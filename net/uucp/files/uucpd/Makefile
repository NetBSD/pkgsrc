#	$NetBSD: Makefile,v 1.1 2007/03/15 20:02:20 christos Exp $
#	from: @(#)Makefile	8.1 (Berkeley) 6/4/93

PROG=	uucpd
MAN=	uucpd.8
LDADD+= -lcrypt -lutil
DPADD+=	${LIBCRYPT} ${LIBUTIL}
CPPFLAGS+=-DSUPPORT_UTMP -DSUPPORT_UTMPX

.include <bsd.prog.mk>
