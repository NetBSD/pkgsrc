# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/06/23 07:08:29 mrg Exp $
#
# This Makefile fragment is included by packages that use mjpegtools.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(MJPEGTOOLS_BUILDLINK2_MK)
MJPEGTOOLS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			mjpegtools
BUILDLINK_DEPENDS.mjpegtools?=		mjpegtools>=1.6.1
BUILDLINK_PKGSRCDIR.mjpegtools?=		../../graphics/mjpegtools

EVAL_PREFIX+=	BUILDLINK_PREFIX.mjpegtools=mjpegtools
BUILDLINK_PREFIX.mjpegtools_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.mjpegtools+=	include/mjpegtools/audiolib.h
BUILDLINK_FILES.mjpegtools+=	include/mjpegtools/editlist.h
BUILDLINK_FILES.mjpegtools+=	include/mjpegtools/frequencies.h
BUILDLINK_FILES.mjpegtools+=	include/mjpegtools/jpegutils.h
BUILDLINK_FILES.mjpegtools+=	include/mjpegtools/lav_io.h
BUILDLINK_FILES.mjpegtools+=	include/mjpegtools/liblavplay.h
BUILDLINK_FILES.mjpegtools+=	include/mjpegtools/liblavrec.h
BUILDLINK_FILES.mjpegtools+=	include/mjpegtools/mjpeg_logging.h
BUILDLINK_FILES.mjpegtools+=	include/mjpegtools/mjpeg_types.h
BUILDLINK_FILES.mjpegtools+=	include/mjpegtools/mpegconsts.h
BUILDLINK_FILES.mjpegtools+=	include/mjpegtools/mpegtimecode.h
BUILDLINK_FILES.mjpegtools+=	include/mjpegtools/yuv4mpeg.h
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
