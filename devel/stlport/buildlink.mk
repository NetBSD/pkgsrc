# $NetBSD: buildlink.mk,v 1.2 2001/12/15 11:51:01 martti Exp $
#
# This Makefile fragment is included by packages that use stlport.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.stlport to the dependency pattern
#     for the version of stlport desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(STLPORT_BUILDLINK_MK)
STLPORT_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.stlport?=	stlport>=4.0
DEPENDS+=	${BUILDLINK_DEPENDS.stlport}:../../devel/stlport

EVAL_PREFIX+=			BUILDLINK_PREFIX.stlport=stlport
BUILDLINK_PREFIX.stlport_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.stlport=	include/stlport/*
BUILDLINK_FILES.stlport+=	include/stlport/*/*
BUILDLINK_FILES.stlport+=	lib/libstlport*

BUILDLINK_TARGETS.stlport=	stlport-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.stlport}

pre-configure: ${BUILDLINK_TARGETS.stlport}
stlport-buildlink: _BUILDLINK_USE

.endif	# STLPORT_BUILDLINK_MK
