# $NetBSD: buildlink2.mk,v 1.2 2004/01/26 12:45:44 jmmv Exp $
#
# This Makefile fragment is included by packages that use mjpegtools.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(MJPEGTOOLS_BUILDLINK2_MK)
MJPEGTOOLS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			mjpegtools
BUILDLINK_DEPENDS.mjpegtools?=		mjpegtools>=1.6.1.90nb3
BUILDLINK_PKGSRCDIR.mjpegtools?=	../../multimedia/mjpegtools

EVAL_PREFIX+=	BUILDLINK_PREFIX.mjpegtools=mjpegtools
BUILDLINK_PREFIX.mjpegtools_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.mjpegtools+=	include/mjpegtools/*
BUILDLINK_FILES.mjpegtools+=	include/mjpegtools/mpeg2enc/*
BUILDLINK_FILES.mjpegtools+=	include/mjpegtools/mplex/*
BUILDLINK_FILES.mjpegtools+=	lib/liblavfile-1.6.*
BUILDLINK_FILES.mjpegtools+=	lib/liblavfile.*
BUILDLINK_FILES.mjpegtools+=	lib/liblavjpeg-1.6.*
BUILDLINK_FILES.mjpegtools+=	lib/liblavjpeg.*
BUILDLINK_FILES.mjpegtools+=	lib/liblavplay-1.6.*
BUILDLINK_FILES.mjpegtools+=	lib/liblavplay.*
BUILDLINK_FILES.mjpegtools+=	lib/libmjpegutils.*
BUILDLINK_FILES.mjpegtools+=	lib/pkgconfig/mjpegtools.pc

.include "../../graphics/jpeg/buildlink2.mk"

BUILDLINK_TARGETS+=	mjpegtools-buildlink

mjpegtools-buildlink: _BUILDLINK_USE

.endif	# MJPEGTOOLS_BUILDLINK2_MK
