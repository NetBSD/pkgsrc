# $NetBSD: buildlink.mk,v 1.4 2001/06/11 01:59:36 jlam Exp $
#
# This Makefile fragment is included by packages that use freetype.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define FREETYPE_REQD to the version of freetype desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(FREETYPE_BUILDLINK_MK)
FREETYPE_BUILDLINK_MK=	# defined

FREETYPE_REQD?=		1.3.1
DEPENDS+=		freetype-lib>=${FREETYPE_REQD}:../../graphics/freetype-lib

BUILDLINK_PREFIX.freetype=	${LOCALBASE}
BUILDLINK_FILES.freetype=	include/freetype/*
BUILDLINK_FILES.freetype+=	lib/libttf.*

.include "../../devel/gettext-lib/buildlink.mk"

BUILDLINK_TARGETS.freetype=	freetype-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.freetype}

pre-configure: ${BUILDLINK_TARGETS.freetype}
freetype-buildlink: _BUILDLINK_USE

.include "../../mk/bsd.buildlink.mk"

.endif	# FREETYPE_BUILDLINK_MK
