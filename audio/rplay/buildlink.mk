# $NetBSD: buildlink.mk,v 1.4 2001/07/27 13:33:20 jlam Exp $
#
# This Makefile fragment is included by packages that use rplay.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.rplay to the dependency pattern
#     for the version of rplay desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(RPLAY_BUILDLINK_MK)
RPLAY_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.rplay?=	rplay>=3.3.2
DEPENDS+=	${BUILDLINK_DEPENDS.rplay}:../../audio/rplay

EVAL_PREFIX+=		BUILDLINK_PREFIX.rplay=rplay
BUILDLINK_PREFIX.rplay_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.rplay=	include/rplay.h
BUILDLINK_FILES.rplay+=	lib/librplay.*

BUILDLINK_TARGETS.rplay=	rplay-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.rplay}

pre-configure: ${BUILDLINK_TARGETS.rplay}
rplay-buildlink: _BUILDLINK_USE

.endif	# RPLAY_BUILDLINK_MK
