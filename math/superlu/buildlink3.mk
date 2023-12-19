# $NetBSD: buildlink3.mk,v 1.12 2023/12/19 12:23:18 thor Exp $

BUILDLINK_TREE+=	superlu

.if !defined(SUPERLU_BUILDLINK3_MK)
SUPERLU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.superlu+=	superlu>=5.0

BUILDLINK_ABI_DEPENDS.superlu?=	superlu>=6.0.1
BUILDLINK_PKGSRCDIR.superlu?=	../../math/superlu
.endif # SUPERLU_BUILDLINK3_MK

BUILDLINK_TREE+=	-superlu
