# $NetBSD: Makefile,v 1.1.1.1 2001/03/06 02:58:39 itojun Exp $

BINDIR=	${PREFIX}/bin
PROG=	tcpdmerge
NOMAN=	yes

LDADD+=	-lpcap
DPADD+=	${LIBPCAP}

.include <bsd.prog.mk>
