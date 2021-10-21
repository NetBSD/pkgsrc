# $NetBSD: buildlink3.mk,v 1.3 2021/10/21 20:33:07 kim Exp $

BUILDLINK_TREE+=	grpc

.if !defined(GRPC_BUILDLINK3_MK)
GRPC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.grpc+=	grpc>=1.11.0
BUILDLINK_ABI_DEPENDS.grpc?=	grpc>=1.41.0nb1
BUILDLINK_PKGSRCDIR.grpc?=	../../net/grpc

.include "../../devel/protobuf/buildlink3.mk"
.endif	# GRPC_BUILDLINK3_MK

BUILDLINK_TREE+=	-grpc
