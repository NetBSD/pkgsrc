# $NetBSD: buildlink.mk,v 1.1 2002/04/09 22:42:08 jlam Exp $
#
# This Makefile fragment is included by packages that use gle.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.gle to the dependency pattern
#     for the version of gle desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(GLE_BUILDLINK_MK)
GLE_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.gle?=	gle>=3.0.3
DEPENDS+=		${BUILDLINK_DEPENDS.gle}:../../graphics/gle

EVAL_PREFIX+=			BUILDLINK_PREFIX.gle=gle
BUILDLINK_PREFIX.gle_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gle=		include/GL/gle.h
BUILDLINK_FILES.gle+=		lib/libgle.*

.include "../../graphics/Mesa/buildlink.mk"

BUILDLINK_TARGETS.gle=	gle-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.gle}

pre-configure: ${BUILDLINK_TARGETS.gle}
gle-buildlink: _BUILDLINK_USE

.endif	# GLE_BUILDLINK_MK
