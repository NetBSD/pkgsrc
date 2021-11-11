# $NetBSD: buildlink3.mk,v 1.11 2021/11/11 12:02:46 kim Exp $

BUILDLINK_TREE+=	protobuf

.if !defined(PROTOBUF_BUILDLINK3_MK)
PROTOBUF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.protobuf+=	protobuf>=3.0.0
BUILDLINK_ABI_DEPENDS.protobuf+=	protobuf>=3.19.0nb1
BUILDLINK_PKGSRCDIR.protobuf?=		../../devel/protobuf

GCC_REQD+=	4.8

.include "../../devel/zlib/buildlink3.mk"
.endif	# PROTOBUF_BUILDLINK3_MK

BUILDLINK_TREE+=	-protobuf
