# $NetBSD: buildlink3.mk,v 1.5 2024/04/22 13:23:55 nikita Exp $

BUILDLINK_TREE+=	nim

.if !defined(NIM_BUILDLINK3_MK)
NIM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nim+=	nim>=2.0.4
BUILDLINK_ABI_DEPENDS.nim+=	nim>=2.0.4
BUILDLINK_PKGSRCDIR.nim?=	../../lang/nim

.endif # NIM_BUILDLINK3_MK

BUILDLINK_TREE+=	-nim
