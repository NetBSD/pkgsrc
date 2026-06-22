# $NetBSD: buildlink3.mk,v 1.18 2026/06/22 19:38:46 wiz Exp $

BUILDLINK_TREE+=	protobuf-c

.if !defined(PROTOBUF_C_BUILDLINK3_MK)
PROTOBUF_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.protobuf-c+=	protobuf-c>=1.1.1
BUILDLINK_ABI_DEPENDS.protobuf-c+=	protobuf-c>=1.5.2nb4
BUILDLINK_PKGSRCDIR.protobuf-c?=	../../devel/protobuf-c

.include "../../devel/protobuf/buildlink3.mk"
.endif	# PROTOBUF_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-protobuf-c
