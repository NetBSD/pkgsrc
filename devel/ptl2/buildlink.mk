# $NetBSD: buildlink.mk,v 1.2 2002/07/12 09:57:43 skrll Exp $
#
# This Makefile fragment is included by packages that use ptl2.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.ptl2 to the dependency pattern
#     for the version of ptl2 desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(PTL2_BUILDLINK_MK)
PTL2_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.ptl2?=	ptl>=2.1.7
DEPENDS+=	${BUILDLINK_DEPENDS.ptl2}:../../devel/ptl2

EVAL_PREFIX+=			BUILDLINK_PREFIX.ptl2=ptl
BUILDLINK_PREFIX.ptl2_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.ptl2=		PTL/include/*/*/*/*.h
BUILDLINK_FILES.ptl2+=		PTL/include/*/*/*.h
BUILDLINK_FILES.ptl2+=		PTL/include/*/*.h
BUILDLINK_FILES.ptl2+=		PTL/include/*.h
BUILDLINK_FILES.ptl2+=		lib/libPTL.*

BUILDLINK_TARGETS.ptl2=	ptl2-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.ptl2}

pre-configure: ${BUILDLINK_TARGETS.ptl2}
ptl2-buildlink: _BUILDLINK_USE

.endif	# PTL2_BUILDLINK_MK
