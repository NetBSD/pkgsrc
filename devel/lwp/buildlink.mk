# $NetBSD: buildlink.mk,v 1.4 2001/06/11 01:59:35 jlam Exp $
#
# This Makefile fragment is included by packages that use lwp.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define LWP_REQD to the version of lwp desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LWP_BUILDLINK_MK)
LWP_BUILDLINK_MK=	# defined

LWP_REQD?=		1.6
DEPENDS+=		lwp>=${LWP_REQD}:../../devel/lwp

BUILDLINK_PREFIX.lwp=	${LOCALBASE}
BUILDLINK_FILES.lwp=	include/lwp/*
BUILDLINK_FILES.lwp+=	lib/liblwp.*

BUILDLINK_TARGETS.lwp=	lwp-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.lwp}

pre-configure: ${BUILDLINK_TARGETS.lwp}
lwp-buildlink: _BUILDLINK_USE

.include "../../mk/bsd.buildlink.mk"

.endif	# LWP_BUILDLINK_MK
