#	$NetBSD: Makefile,v 1.2 2003/12/13 17:45:59 seb Exp $

MKMAN=	no

.include <bsd.own.mk>

.PATH: ${BSDSRCDIR}/sbin/sysctl

.include "${BSDSRCDIR}/sbin/sysctl/Makefile"

LDADD+=	${.CURDIR}/../lib/libkver.a
CPPFLAGS+=	-I${BSDSRCDIR}/sys
LDSTATIC?=	-static
