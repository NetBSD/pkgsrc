# $NetBSD: buildlink3.mk,v 1.2 2013/03/29 09:17:26 asau Exp $

BUILDLINK_TREE+=	protobuf

.if !defined(PROTOBUF_BUILDLINK3_MK)
PROTOBUF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.protobuf+=	protobuf>=2.4.1
BUILDLINK_PKGSRCDIR.protobuf?=	../../devel/protobuf

.include "../../devel/zlib/buildlink3.mk"
.endif	# PROTOBUF_BUILDLINK3_MK

BUILDLINK_TREE+=	-protobuf
