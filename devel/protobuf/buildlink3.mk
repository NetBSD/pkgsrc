# $NetBSD: buildlink3.mk,v 1.1 2012/07/20 03:13:48 agc Exp $

BUILDLINK_TREE+=	protobuf

.if !defined(PROTOBUF_BUILDLINK3_MK)
PROTOBUF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.protobuf+=	protobuf>=2.4.1
BUILDLINK_PKGSRCDIR.protobuf?=	../../devel/protobuf

.endif	# PROTOBUF_BUILDLINK3_MK

BUILDLINK_TREE+=	-protobuf
