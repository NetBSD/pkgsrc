# $NetBSD: buildlink3.mk,v 1.7 2023/11/02 12:20:03 wiz Exp $

BUILDLINK_TREE+=	protobuf-c

.if !defined(PROTOBUF_C_BUILDLINK3_MK)
PROTOBUF_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.protobuf-c+=	protobuf-c>=1.1.1
BUILDLINK_ABI_DEPENDS.protobuf-c+=	protobuf-c>=1.4.1nb1
BUILDLINK_PKGSRCDIR.protobuf-c?=	../../devel/protobuf-c

.include "../../devel/protobuf/buildlink3.mk"
.endif	# PROTOBUF_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-protobuf-c
