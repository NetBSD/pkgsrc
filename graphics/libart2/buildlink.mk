# $NetBSD: buildlink.mk,v 1.1.1.1.2.2 2002/06/23 18:46:34 jlam Exp $
#
# This Makefile fragment is included by packages that use the library
# provided by libart2.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.libart2 to the dependency
#     pattern for the version of libart2 desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(LIBART2_BUILDLINK_MK)
LIBART2_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.libart2?=	libart2>=2.3.8
DEPENDS+=	${BUILDLINK_DEPENDS.libart2}:../../graphics/libart2

EVAL_PREFIX+=	BUILDLINK_PREFIX.libart2=libart2
BUILDLINK_PREFIX.libart2=	${LOCALBASE}
BUILDLINK_FILES.libart2=	bin/libart22-config
BUILDLINK_FILES.libart2+=	include/libart2-2.0/libart2_lgpl/*
BUILDLINK_FILES.libart2+=	lib/libart2_lgpl_2.*

BUILDLINK_TARGETS.libart2=	libart2-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.libart2}

pre-configure: ${BUILDLINK_TARGETS.libart2}
libart2-buildlink: _BUILDLINK_USE

.endif	# LIBART2_BUILDLINK_MK
