# $NetBSD: suse.x86_64.mk,v 1.2 2008/09/03 09:45:59 obache Exp $

# SuSE x86_64 RPMs; the -devel version is necessary for libGL.so et.al.
# symlinks only.
#
DISTFILES+=	xorg-x11-Mesa-6.8.2-100.13.${SUSE_ARCH}.rpm
DISTFILES+=	xorg-x11-Mesa-devel-6.8.2-100.13.${SUSE_ARCH}.rpm
DISTFILES+=	xorg-x11-Mesa-32bit-6.8.2-100.13.${SUSE_ARCH}.rpm
DISTFILES+=	xorg-x11-Mesa-devel-32bit-6.8.2-100.13.${SUSE_ARCH}.rpm
