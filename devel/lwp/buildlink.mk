# $NetBSD: buildlink.mk,v 1.8 2001/07/27 13:33:25 jlam Exp $
#
# This Makefile fragment is included by packages that use lwp.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.lwp to the dependency pattern
#     for the version of lwp desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LWP_BUILDLINK_MK)
LWP_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.lwp?=	lwp>=1.6
DEPENDS+=		${BUILDLINK_DEPENDS.lwp}:../../devel/lwp

EVAL_PREFIX+=		BUILDLINK_PREFIX.lwp=lwp
BUILDLINK_PREFIX.lwp_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.lwp=	include/lwp/*
BUILDLINK_FILES.lwp+=	lib/liblwp.*

BUILDLINK_TARGETS.lwp=	lwp-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.lwp}

pre-configure: ${BUILDLINK_TARGETS.lwp}
lwp-buildlink: _BUILDLINK_USE

.endif	# LWP_BUILDLINK_MK
