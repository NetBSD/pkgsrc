# $NetBSD: buildlink.mk,v 1.8 2001/07/27 13:33:28 jlam Exp $
#
# This Makefile fragment is included by packages that use freetype.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.freetype to the dependency pattern
#     for the version of freetype desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(FREETYPE_BUILDLINK_MK)
FREETYPE_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.freetype?=	freetype-lib>=1.3.1
DEPENDS+=	${BUILDLINK_DEPENDS.freetype}:../../graphics/freetype-lib

EVAL_PREFIX+=			BUILDLINK_PREFIX.freetype=freetype-lib
BUILDLINK_PREFIX.freetype_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.freetype=	include/freetype/*
BUILDLINK_FILES.freetype+=	lib/libttf.*

.include "../../devel/gettext-lib/buildlink.mk"

BUILDLINK_TARGETS.freetype=	freetype-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.freetype}

pre-configure: ${BUILDLINK_TARGETS.freetype}
freetype-buildlink: _BUILDLINK_USE

.endif	# FREETYPE_BUILDLINK_MK
