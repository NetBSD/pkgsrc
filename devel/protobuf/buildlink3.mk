# $NetBSD: buildlink3.mk,v 1.8 2020/05/21 16:30:33 adam Exp $

BUILDLINK_TREE+=	protobuf

.if !defined(PROTOBUF_BUILDLINK3_MK)
PROTOBUF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.protobuf+=	protobuf>=3.0.0
BUILDLINK_ABI_DEPENDS.protobuf+=	protobuf>=3.12.0
BUILDLINK_PKGSRCDIR.protobuf?=		../../devel/protobuf

.include "../../devel/zlib/buildlink3.mk"
.endif	# PROTOBUF_BUILDLINK3_MK

BUILDLINK_TREE+=	-protobuf
