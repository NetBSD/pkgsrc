# $NetBSD: buildlink.mk,v 1.2 2001/06/23 19:26:50 jlam Exp $
#
# This Makefile fragment is included by packages that use pilot-link.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.pilot-link to the dependency pattern
#     for the version of pilot-link desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(PILOT_LINK_BUILDLINK_MK)
PILOT_LINK_BUILDLINK_MK=	# defined

BUILDLINK_DEPENDS.pilot-link?=	pilot-link>=0.9.3
DEPENDS+=	${BUILDLINK_DEPENDS.pilot-link}:../../comms/pilot-link

BUILDLINK_PREFIX.pilot-link=	${LOCALBASE}
BUILDLINK_FILES.pilot-link=	include/pi-*.*
BUILDLINK_FILES.pilot-link+=	lib/libpicc.*
BUILDLINK_FILES.pilot-link+=	lib/libpisock.*

BUILDLINK_TARGETS.pilot-link=	pilot-link-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.pilot-link}

pre-configure: ${BUILDLINK_TARGETS.pilot-link}
pilot-link-buildlink: _BUILDLINK_USE

.include "../../mk/bsd.buildlink.mk"

.endif	# PILOT_LINK_BUILDLINK_MK
