# $NetBSD: buildlink2.mk,v 1.1.2.2 2002/06/06 06:54:40 jlam Exp $
#
# This Makefile fragment is included by packages that use libjpeg.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.jpeg to the dependency pattern
#     for the version of libjpeg desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(JPEG_BUILDLINK2_MK)
JPEG_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.jpeg?=	jpeg-6b
DEPENDS+=	${BUILDLINK_DEPENDS.jpeg}:../../graphics/jpeg

EVAL_PREFIX+=	BUILDLINK_PREFIX.jpeg=jpeg
BUILDLINK_PREFIX.jpeg_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.jpeg=	include/jconfig.h
BUILDLINK_FILES.jpeg+=	include/jpeglib.h
BUILDLINK_FILES.jpeg+=	include/jmorecfg.h
BUILDLINK_FILES.jpeg+=	include/jerror.h
BUILDLINK_FILES.jpeg+=	lib/libjpeg.*

BUILDLINK_TARGETS+=	jpeg-buildlink

jpeg-buildlink: _BUILDLINK_USE

.endif	# JPEG_BUILDLINK2_MK
