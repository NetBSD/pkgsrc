# $NetBSD: buildlink.mk,v 1.1 2001/06/30 09:28:15 zuntum Exp $
#
# This Makefile fragment is included by packages that use rx.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.rx to the dependency pattern
#     for the version of rx desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(RX_BUILDLINK_MK)
RX_BUILDLINK_MK=	# defined

BUILDLINK_DEPENDS.rx?=	rx>=1.5
DEPENDS+=	${BUILDLINK_DEPENDS.rx}:../../devel/rx

BUILDLINK_PREFIX.rx=	${LOCALBASE}
BUILDLINK_FILES.rx=	include/rxposix.h
BUILDLINK_FILES.rx+=	lib/librx.*

BUILDLINK_TARGETS.rx=	rx-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.rx}

pre-configure: ${BUILDLINK_TARGETS.rx}
rx-buildlink: _BUILDLINK_USE

.include "../../mk/bsd.buildlink.mk"

.endif	# RX_BUILDLINK_MK
