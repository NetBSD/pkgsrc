#	$NetBSD: Makefile,v 1.5 2006/12/07 19:10:21 rpaulo Exp $

PROG=   shlock

.if (${OPSYS} == SunOS || ${OPSYS} == Darwin || ${OPSYS} == DragonFly || \
    ${OPSYS} == Linux)
NOMAN=          YES
.endif

.include <bsd.prog.mk>
