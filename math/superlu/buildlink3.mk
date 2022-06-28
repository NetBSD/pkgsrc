# $NetBSD: buildlink3.mk,v 1.11 2022/06/28 11:34:45 wiz Exp $

BUILDLINK_TREE+=	superlu

.if !defined(SUPERLU_BUILDLINK3_MK)
SUPERLU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.superlu+=	superlu>=5.0

BUILDLINK_ABI_DEPENDS.superlu?=	superlu>=5.2.1nb4
BUILDLINK_PKGSRCDIR.superlu?=	../../math/superlu
BUILDLINK_DEPMETHOD.superlu?=	build
.endif # SUPERLU_BUILDLINK3_MK

BUILDLINK_TREE+=	-superlu
