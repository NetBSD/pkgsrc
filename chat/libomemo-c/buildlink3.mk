# $NetBSD: buildlink3.mk,v 1.1 2025/08/15 09:45:58 gdt Exp $

BUILDLINK_TREE+=	libomemo-c

.if !defined(LIBOMEMO_C_BUILDLINK3_MK)
LIBOMEMO_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libomemo-c+=	libomemo-c>=0.5.1
BUILDLINK_PKGSRCDIR.libomemo-c?=	../../chat/libomemo-c

.include "../../devel/protobuf-c/buildlink3.mk"
.endif	# LIBOMEMO_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-libomemo-c
