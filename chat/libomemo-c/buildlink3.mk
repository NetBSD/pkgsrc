# $NetBSD: buildlink3.mk,v 1.4 2026/06/22 19:38:45 wiz Exp $

BUILDLINK_TREE+=	libomemo-c

.if !defined(LIBOMEMO_C_BUILDLINK3_MK)
LIBOMEMO_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libomemo-c+=	libomemo-c>=0.5.1
BUILDLINK_ABI_DEPENDS.libomemo-c?=	libomemo-c>=0.5.1nb3
BUILDLINK_PKGSRCDIR.libomemo-c?=	../../chat/libomemo-c

.include "../../devel/protobuf-c/buildlink3.mk"
.endif	# LIBOMEMO_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-libomemo-c
