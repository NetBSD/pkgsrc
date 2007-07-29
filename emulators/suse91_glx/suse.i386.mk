# $NetBSD: suse.i386.mk,v 1.1 2007/07/29 05:19:11 jlam Exp $

# SuSE i386 RPMs; the -devel version is necessary for libGL.so et.al.
# symlinks only.
#
DISTFILES+=	XFree86-Mesa-4.3.99.902-40.${SUSE_ARCH}.rpm
DISTFILES+=	XFree86-Mesa-devel-4.3.99.902-40.${SUSE_ARCH}.rpm
