# $NetBSD: buildlink3.mk,v 1.17 2023/11/02 14:33:58 wiz Exp $

BUILDLINK_TREE+=	protobuf

.if !defined(PROTOBUF_BUILDLINK3_MK)
PROTOBUF_BUILDLINK3_MK:=

USE_CXX_FEATURES+=	c++14

BUILDLINK_API_DEPENDS.protobuf+=	protobuf>=24.4
BUILDLINK_ABI_DEPENDS.protobuf+=	protobuf>=24.4
BUILDLINK_PKGSRCDIR.protobuf?=		../../devel/protobuf

BUILDLINK_FILES.protobuf+=	bin/protoc
BUILDLINK_FILES.protobuf+=	bin/protoc-*
.include "../../devel/abseil/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.endif	# PROTOBUF_BUILDLINK3_MK

BUILDLINK_TREE+=	-protobuf
