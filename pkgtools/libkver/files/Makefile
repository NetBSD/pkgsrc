#	$NetBSD: Makefile,v 1.1.1.1 2003/07/11 14:50:37 seb Exp $

.include "${.CURDIR}/Makefile.inc"

SUBDIR=		lib

LDD_SYSCTL!=	ldd /sbin/sysctl 2>&1
.if empty(LDD_SYSCTL:M*libc*)
SUBDIR+=	sysctl
.endif

.include <bsd.subdir.mk>
