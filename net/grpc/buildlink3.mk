# $NetBSD: buildlink3.mk,v 1.8 2022/08/19 06:25:22 wiz Exp $

BUILDLINK_TREE+=	grpc

.if !defined(GRPC_BUILDLINK3_MK)
GRPC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.grpc+=	grpc>=1.11.0
BUILDLINK_ABI_DEPENDS.grpc+=	grpc>=1.48.0
BUILDLINK_PKGSRCDIR.grpc?=	../../net/grpc

.include "../../devel/protobuf/buildlink3.mk"
.endif	# GRPC_BUILDLINK3_MK

BUILDLINK_TREE+=	-grpc
