# $NetBSD: suse.i386.mk,v 1.1 2007/07/29 05:18:47 jlam Exp $

# SuSE i386 RPMs; the -devel version is necessary for libGL.so et.al.
# symlinks only.
#
DISTFILES+=	xorg-x11-Mesa-6.8.2-100.${SUSE_ARCH}.rpm
DISTFILES+=	xorg-x11-Mesa-devel-6.8.2-100.${SUSE_ARCH}.rpm
