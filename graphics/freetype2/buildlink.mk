# $NetBSD: buildlink.mk,v 1.4 2001/07/02 05:33:59 jlam Exp $
#
# This Makefile fragment is included by packages that use freetype2.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.freetype2 to the dependency pattern
#     for the version of freetype2 desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(FREETYPE2_BUILDLINK_MK)
FREETYPE2_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.freetype2?=	freetype2>=2.0.3
DEPENDS+=	${BUILDLINK_DEPENDS.freetype2}:../../graphics/freetype2

BUILDLINK_PREFIX.freetype2=	${LOCALBASE}
BUILDLINK_FILES.freetype2=	include/ft2build.h
BUILDLINK_FILES.freetype2+=	include/freetype2/freetype/*
BUILDLINK_FILES.freetype2+=	include/freetype2/freetype/cache/*
BUILDLINK_FILES.freetype2+=	include/freetype2/freetype/config/*
BUILDLINK_FILES.freetype2+=	include/freetype2/freetype/internal/*
BUILDLINK_FILES.freetype2+=	lib/libfreetype.*

.include "../../devel/gettext-lib/buildlink.mk"

BUILDLINK_TARGETS.freetype2=	freetype2-buildlink
BUILDLINK_TARGETS.freetype2+=	freetype2-buildlink-config-wrapper
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.freetype2}

BUILDLINK_CONFIG.freetype2=	${LOCALBASE}/bin/freetype-config
BUILDLINK_CONFIG_WRAPPER.freetype2=	${BUILDLINK_DIR}/bin/freetype-config

.if defined(USE_CONFIG_WRAPPER) && defined(GNU_CONFIGURE)
FREETYPE_CONFIG?=	${BUILDLINK_CONFIG_WRAPPER.freetype2}
CONFIGURE_ENV+=		FREETYPE_CONFIG="${FREETYPE_CONFIG}"
.endif

pre-configure: ${BUILDLINK_TARGETS.freetype2}
freetype2-buildlink: _BUILDLINK_USE
freetype2-buildlink-config-wrapper: _BUILDLINK_CONFIG_WRAPPER_USE

.endif	# FREETYPE2_BUILDLINK_MK
