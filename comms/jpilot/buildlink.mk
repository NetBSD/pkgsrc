# $NetBSD: buildlink.mk,v 1.7 2002/09/10 16:06:34 wiz Exp $
#
# This Makefile fragment is included by packages that use jpilot.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.jpilot to the dependency pattern
#     for the version of jpilot desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(JPILOT_BUILDLINK_MK)
JPILOT_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.jpilot?=	jpilot>=0.99nb2
BUILD_DEPENDS+=			${BUILDLINK_DEPENDS.jpilot}:../../comms/jpilot

EVAL_PREFIX+=			BUILDLINK_PREFIX.jpilot=jpilot
BUILDLINK_PREFIX.jpilot_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.jpilot=		include/jpilot/*

.include "../../x11/gtk/buildlink.mk"

BUILDLINK_TARGETS.jpilot=	jpilot-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.jpilot}

pre-configure: ${BUILDLINK_TARGETS.jpilot}
jpilot-buildlink: _BUILDLINK_USE

.endif	# JPILOT_BUILDLINK_MK
