# $NetBSD: buildlink3.mk,v 1.12 2023/07/13 13:45:42 nia Exp $

BUILDLINK_TREE+=	protobuf

.if !defined(PROTOBUF_BUILDLINK3_MK)
PROTOBUF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.protobuf+=	protobuf>=3.0.0
BUILDLINK_ABI_DEPENDS.protobuf+=	protobuf>=3.19.0nb1
BUILDLINK_PKGSRCDIR.protobuf?=		../../devel/protobuf

.include "../../devel/zlib/buildlink3.mk"
.endif	# PROTOBUF_BUILDLINK3_MK

BUILDLINK_TREE+=	-protobuf
