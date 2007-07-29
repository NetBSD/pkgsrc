# $NetBSD: suse.x86_64.mk,v 1.1 2007/07/29 05:18:40 jlam Exp $

# SuSE x86_64 RPMs
DISTFILES+=	aaa_base-10.0-28.${SUSE_ARCH}.rpm
DISTFILES+=	bash-3.0-17.${SUSE_ARCH}.rpm
DISTFILES+=	coreutils-5.3.0-20.2.${SUSE_ARCH}.rpm
DISTFILES+=	glibc-2.3.5-40.${SUSE_ARCH}.rpm
DISTFILES+=	libgcc-4.0.2_20050901-3.${SUSE_ARCH}.rpm
DISTFILES+=	libacl-2.2.31-3.${SUSE_ARCH}.rpm
DISTFILES+=	libattr-2.4.24-2.${SUSE_ARCH}.rpm
DISTFILES+=	libselinux-1.23.11-3.${SUSE_ARCH}.rpm
DISTFILES+=	libstdc++-4.0.2_20050901-3.${SUSE_ARCH}.rpm
DISTFILES+=	ncurses-5.4-71.${SUSE_ARCH}.rpm
DISTFILES+=	readline-5.0-9.${SUSE_ARCH}.rpm
DISTFILES+=	zlib-1.2.3-3.${SUSE_ARCH}.rpm

LINUX_LIBSUBDIR=	lib64
