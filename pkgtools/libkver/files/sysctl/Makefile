#	$NetBSD: Makefile,v 1.1.1.1 2003/07/11 14:50:37 seb Exp $

MKMAN=	no

.include <bsd.own.mk>

.PATH: ${BSDSRCDIR}/sbin/sysctl

BINDIR=		/sbin

.include "${BSDSRCDIR}/sbin/sysctl/Makefile"

LDADD+=	${.CURDIR}/../lib/libkver.a
CPPFLAGS+=	-I${BSDSRCDIR}/sys
LDSTATIC?=	-static
