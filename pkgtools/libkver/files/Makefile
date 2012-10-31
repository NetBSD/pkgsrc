#	$NetBSD: Makefile,v 1.4 2012/10/31 14:41:55 apb Exp $

SUBDIR=		kver lib

.ifndef(LDD_SYSCTL)
LDD_SYSCTL!=	ldd /sbin/sysctl 2>&1
.endif
.if empty(LDD_SYSCTL:M*libc*)
SUBDIR+=	sysctl
.endif

.include <bsd.subdir.mk>
