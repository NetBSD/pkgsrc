#	$NetBSD: Makefile,v 1.2 2003/07/20 15:37:47 seb Exp $

SUBDIR=		lib

LDD_SYSCTL!=	ldd /sbin/sysctl 2>&1
.if empty(LDD_SYSCTL:M*libc*)
SUBDIR+=	sysctl
.endif

.include <bsd.subdir.mk>
.include "${.CURDIR}/Makefile.inc"
