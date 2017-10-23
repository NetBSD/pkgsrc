# $NetBSD: buildlink3.mk,v 1.1 2017/10/23 15:48:04 minskim Exp $

BUILDLINK_TREE+=	grpc

.if !defined(GRPC_BUILDLINK3_MK)
GRPC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.grpc+=	grpc>=1.6.7
BUILDLINK_PKGSRCDIR.grpc?=	../../net/grpc

.endif	# GRPC_BUILDLINK3_MK

BUILDLINK_TREE+=	-grpc
