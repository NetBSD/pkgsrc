# $NetBSD: buildlink.mk,v 1.1 2001/06/15 07:54:41 jlam Exp $
#
# This Makefile fragment is included by packages that use pth.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define PTH_REQD to the version of pth desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(PTH_BUILDLINK_MK)
PTH_BUILDLINK_MK=	# defined

PTH_REQD?=		1.3.2
DEPENDS+=		pth>=${PTH_REQD}:../../devel/pth

BUILDLINK_PREFIX.pth=	${LOCALBASE}
BUILDLINK_FILES.pth=	include/pth.h
BUILDLINK_FILES.pth+=	include/pthread.h
BUILDLINK_FILES.pth+=	lib/libpth.*

BUILDLINK_TARGETS.pth=	pth-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.pth}

pre-configure: ${BUILDLINK_TARGETS.pth}
pth-buildlink: _BUILDLINK_USE

.include "../../mk/bsd.buildlink.mk"

.endif	# PTH_BUILDLINK_MK
