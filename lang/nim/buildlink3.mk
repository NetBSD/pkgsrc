# $NetBSD: buildlink3.mk,v 1.1 2020/05/11 19:45:54 nikita Exp $

BUILDLINK_TREE+=	nim

.if !defined(NIM_BUILDLINK3_MK)
NIM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nim+=	nim>=1.2.0
BUILDLINK_ABI_DEPENDS.nim?=	nim>=1.2.0
BUILDLINK_PKGSRCDIR.nim?=	../../lang/nim

.endif # NIM_BUILDLINK3_MK

BUILDLINK_TREE+=	-nim
