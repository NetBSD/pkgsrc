# $NetBSD: buildlink.mk,v 1.4 2001/06/11 01:59:35 jlam Exp $
#
# This Makefile fragment is included by packages that use rpc2.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define RPC2_REQD to the version of rpc2 desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(RPC2_BUILDLINK_MK)
RPC2_BUILDLINK_MK=	# defined

RPC2_REQD?=		1.10
DEPENDS+=		rpc2>=${RPC2_REQD}:../../devel/rpc2

BUILDLINK_PREFIX.rpc2=	${LOCALBASE}
BUILDLINK_FILES.rpc2=	include/rpc2/*
BUILDLINK_FILES.rpc2+=	lib/libfail.*
BUILDLINK_FILES.rpc2+=	lib/librpc2.*
BUILDLINK_FILES.rpc2+=	lib/libse.*

.include "../../devel/lwp/buildlink.mk"

BUILDLINK_TARGETS.rpc2=		rpc2-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.rpc2}

pre-configure: ${BUILDLINK_TARGETS.rpc2}
rpc2-buildlink: _BUILDLINK_USE

.include "../../mk/bsd.buildlink.mk"

.endif	# RPC2_BUILDLINK_MK
