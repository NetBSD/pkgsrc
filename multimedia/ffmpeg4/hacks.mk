# $NetBSD: hacks.mk,v 1.1.2.2 2020/09/18 18:25:15 bsiegert Exp $

.if !defined(FFMPEG4_HACKS_MK)
FFMPEG4_HACKS_MK=	defined

# [Mon Sep 14 12:41:59 CEST 2020 : he]
# On NetBSD/powerpc, enable -mvsx, to get vec_xl in scope.
.if ${MACHINE_ARCH} == "powerpc"
CFLAGS+=	-mvsx
.endif

.endif	# FFMPEG4_HACKS_MK
