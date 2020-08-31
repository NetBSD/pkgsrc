# $NetBSD: buildlink3.mk,v 1.10 2020/08/31 18:06:30 wiz Exp $

BUILDLINK_TREE+=	superlu

.if !defined(SUPERLU_BUILDLINK3_MK)
SUPERLU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.superlu+=	superlu>=5.0

BUILDLINK_ABI_DEPENDS.superlu?=	superlu>=5.2.1nb1
BUILDLINK_PKGSRCDIR.superlu?=	../../math/superlu
BUILDLINK_DEPMETHOD.superlu?=	build
.endif # SUPERLU_BUILDLINK3_MK

BUILDLINK_TREE+=	-superlu
