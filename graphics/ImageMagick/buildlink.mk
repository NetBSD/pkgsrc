# $NetBSD: buildlink.mk,v 1.6 2001/08/23 21:32:32 jlam Exp $
#
# This Makefile fragment is included by packages that use ImageMagick.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.ImageMagick to the dependency pattern
#     for the version of ImageMagick desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(IMAGEMAGICK_BUILDLINK_MK)
IMAGEMAGICK_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.ImageMagick?=	ImageMagick>=5.2.8
DEPENDS+=	${BUILDLINK_DEPENDS.ImageMagick}:../../graphics/ImageMagick

EVAL_PREFIX+=			BUILDLINK_PREFIX.ImageMagick=ImageMagick
BUILDLINK_PREFIX.ImageMagick_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.ImageMagick=	include/Magick++.h
BUILDLINK_FILES.ImageMagick+=	include/Magick++/*
BUILDLINK_FILES.ImageMagick+=	include/magick/*
BUILDLINK_FILES.ImageMagick+=	lib/libMagick.*
BUILDLINK_FILES.ImageMagick+=	lib/libMagick++.*

.include "../../archivers/bzip2/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/tiff/buildlink.mk"

BUILDLINK_TARGETS.ImageMagick=	ImageMagick-buildlink
BUILDLINK_TARGETS.ImageMagick+=	magick-buildlink-config-wrapper
BUILDLINK_TARGETS.ImageMagick+=	magickpp-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.ImageMagick}

BUILDLINK_CONFIG.magick=	\
	${BUILDLINK_PREFIX.ImageMagick}/bin/Magick-config
BUILDLINK_CONFIG_WRAPPER.magick=	\
	${BUILDLINK_DIR}/bin/Magick-config
BUILDLINK_CONFIG.magickpp=	\
	${BUILDLINK_PREFIX.ImageMagick}/bin/Magick++-config
BUILDLINK_CONFIG_WRAPPER.magickpp=	\
	${BUILDLINK_DIR}/bin/Magick++-config

.if defined(USE_CONFIG_WRAPPER)
MAGICK_CONFIG?=		${BUILDLINK_CONFIG_WRAPPER.magick}
MAGICKPP_CONFIG?=	${BUILDLINK_CONFIG_WRAPPER.magickpp}
CONFIGURE_ENV+=		MAGICK_CONFIG="${MAGICK_CONFIG}"
CONFIGURE_ENV+=		MAGICKPP_CONFIG="${MAGICKPP_CONFIG}"
MAKE_ENV+=		MAGICK_CONFIG="${MAGICK_CONFIG}"
MAKE_ENV+=		MAGICKPP_CONFIG="${MAGICKPP_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.ImageMagick}
ImageMagick-buildlink: _BUILDLINK_USE
magick-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE
magickpp-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# IMAGEMAGICK_BUILDLINK_MK
