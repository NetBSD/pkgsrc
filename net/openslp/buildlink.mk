# $NetBSD: buildlink.mk,v 1.1.1.1 2001/08/18 03:18:43 jlam Exp $
#
# This Makefile fragment is included by packages that use openslp.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.openslp to the dependency pattern
#     for the version of openslp desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(OPENSLP_BUILDLINK_MK)
OPENSLP_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.openslp?=	openslp>=1.0.1
DEPENDS+=	${BUILDLINK_DEPENDS.openslp}:../../net/openslp

EVAL_PREFIX+=			BUILDLINK_PREFIX.openslp=openslp
BUILDLINK_PREFIX.openslp_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.openslp=	include/slp.h
BUILDLINK_FILES.openslp+=	lib/libslp.*

BUILDLINK_TARGETS.openslp=	openslp-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.openslp}

pre-configure: ${BUILDLINK_TARGETS.openslp}
openslp-buildlink: _BUILDLINK_USE

.endif	# OPENSLP_BUILDLINK_MK
