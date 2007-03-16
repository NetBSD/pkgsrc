#	$NetBSD: Makefile,v 1.2 2007/03/16 17:52:30 christos Exp $
#	from: @(#)Makefile	8.1 (Berkeley) 6/4/93

PROG=	uucpd
MAN=	uucpd.8
BINDIR=	@PREFIX@/libexec
MANDIR=	@PREFIX@/man
LDADD+= -lcrypt -lutil
DPADD+=	${LIBCRYPT} ${LIBUTIL}
CPPFLAGS+=-DSUPPORT_UTMP -DSUPPORT_UTMPX

.include <bsd.prog.mk>
