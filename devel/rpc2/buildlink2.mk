# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:18 jlam Exp $

.if !defined(RPC2_BUILDLINK2_MK)
RPC2_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		rpc2
BUILDLINK_DEPENDS.rpc2?=	rpc2>=1.10
BUILDLINK_PKGSRCDIR.rpc2?=	../../devel/rpc2

EVAL_PREFIX+=		BUILDLINK_PREFIX.rpc2=rpc2
BUILDLINK_PREFIX.rpc2_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.rpc2=	include/rpc2/*
BUILDLINK_FILES.rpc2+=	lib/libfail.*
BUILDLINK_FILES.rpc2+=	lib/librpc2.*
BUILDLINK_FILES.rpc2+=	lib/libse.*

.include "../../devel/lwp/buildlink2.mk"

BUILDLINK_TARGETS+=	rpc2-buildlink

rpc2-buildlink: _BUILDLINK_USE

.endif	# RPC2_BUILDLINK2_MK
