# $NetBSD: buildlink.mk,v 1.1 2001/06/22 06:03:14 jlam Exp $
#
# This Makefile fragment is included by packages that use jpilot.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define JPILOT_REQD to the version of jpilot desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(JPILOT_BUILDLINK_MK)
JPILOT_BUILDLINK_MK=	# defined

JPILOT_REQD?=		0.99
BUILD_DEPENDS+=		jpilot>=${JPILOT_REQD}:../../comms/jpilot

BUILDLINK_PREFIX.jpilot=	${LOCALBASE}
BUILDLINK_FILES.jpilot=		include/jpilot/*

BUILDLINK_TARGETS.jpilot=	jpilot-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.jpilot}

pre-configure: ${BUILDLINK_TARGETS.jpilot}
jpilot-buildlink: _BUILDLINK_USE

.include "../../mk/bsd.buildlink.mk"

.endif	# JPILOT_BUILDLINK_MK
