# $NetBSD: suse.x86_64.mk,v 1.1 2007/07/29 05:19:05 jlam Exp $

# SuSE x86_64 RPMs
DISTFILES+=	aaa_base-9.1-0.29.${SUSE_ARCH}.rpm
DISTFILES+=	bash-2.05b-305.1.${SUSE_ARCH}.rpm
DISTFILES+=	coreutils-5.2.1-23.8.${SUSE_ARCH}.rpm
DISTFILES+=	glibc-2.3.3-63.${SUSE_ARCH}.rpm
DISTFILES+=	libacl-2.2.21-54.4.${SUSE_ARCH}.rpm
DISTFILES+=	libattr-2.4.12-44.${SUSE_ARCH}.rpm
DISTFILES+=	libgcc-3.3.3-33.${SUSE_ARCH}.rpm
DISTFILES+=	libselinux-1.8-15.${SUSE_ARCH}.rpm
DISTFILES+=	libstdc++-3.3.3-33.${SUSE_ARCH}.rpm
DISTFILES+=	ncurses-5.4-61.3.${SUSE_ARCH}.rpm
DISTFILES+=	readline-4.3-301.${SUSE_ARCH}.rpm
DISTFILES+=	zlib-1.2.1-70.12.${SUSE_ARCH}.rpm

LINUX_LIBSUBDIR=	lib64
