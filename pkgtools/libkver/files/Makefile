#	$NetBSD: Makefile,v 1.3 2003/12/13 17:45:59 seb Exp $

SUBDIR=		lib

.ifndef(LDD_SYSCTL)
LDD_SYSCTL!=	ldd /sbin/sysctl 2>&1
.endif
.if empty(LDD_SYSCTL:M*libc*)
SUBDIR+=	sysctl
.endif

.include <bsd.subdir.mk>
