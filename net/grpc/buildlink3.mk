# $NetBSD: buildlink3.mk,v 1.4 2021/11/11 12:02:47 kim Exp $

BUILDLINK_TREE+=	grpc

.if !defined(GRPC_BUILDLINK3_MK)
GRPC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.grpc+=	grpc>=1.11.0
BUILDLINK_ABI_DEPENDS.grpc?=	grpc>=1.41.1nb1
BUILDLINK_PKGSRCDIR.grpc?=	../../net/grpc

.include "../../devel/protobuf/buildlink3.mk"
.endif	# GRPC_BUILDLINK3_MK

BUILDLINK_TREE+=	-grpc
