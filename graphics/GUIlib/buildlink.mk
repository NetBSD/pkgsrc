# $NetBSD: buildlink.mk,v 1.1.1.1 2001/07/27 09:30:22 zuntum Exp $
#
# This Makefile fragment is included by packages that use GUIlib.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.GUIlib to the dependency pattern
#     for the version of GUIlib desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(GUIlib_BUILDLINK_MK)
GUIlib_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.GUIlib?=	GUIlib>=1.1.0
DEPENDS+=	${BUILDLINK_DEPENDS.GUIlib}:../../graphics/GUIlib

EVAL_PREFIX+=			BUILDLINK_PREFIX.GUIlib=GUIlib
BUILDLINK_FILES.GUIlib=		include/GUI/*.h
BUILDLINK_FILES.GUIlib+=	lib/libGUI-*
BUILDLINK_FILES.GUIlib+=	lib/libGUI.*

.include "../../devel/SDL/buildlink.mk"

BUILDLINK_TARGETS.GUIlib=	GUIlib-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.GUIlib}

pre-configure: ${BUILDLINK_TARGETS.GUIlib}
GUIlib-buildlink: _BUILDLINK_USE

.endif	# GUIlib_BUILDLINK_MK
