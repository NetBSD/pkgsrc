# $NetBSD: buildlink.mk,v 1.5 2001/07/27 13:33:20 jlam Exp $
#
# This Makefile fragment is included by packages that use nas.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.nas to the dependency pattern
#     for the version of nas desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(NAS_BUILDLINK_MK)
NAS_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.nas?=	nas>=1.4.2
DEPENDS+=	${BUILDLINK_DEPENDS.nas}:../../audio/nas

EVAL_PREFIX+=		BUILDLINK_PREFIX.nas=nas
BUILDLINK_PREFIX.nas_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.nas=	include/audio/*
BUILDLINK_FILES.nas+=	lib/libaudio.*

BUILDLINK_TARGETS.nas=	nas-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.nas}

pre-configure: ${BUILDLINK_TARGETS.nas}
nas-buildlink: _BUILDLINK_USE

.endif	# NAS_BUILDLINK_MK
