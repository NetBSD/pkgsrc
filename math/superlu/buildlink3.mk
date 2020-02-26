# $NetBSD: buildlink3.mk,v 1.9 2020/02/26 16:29:43 wiz Exp $

BUILDLINK_TREE+=	superlu

.if !defined(SUPERLU_BUILDLINK3_MK)
SUPERLU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.superlu+=	superlu>=5.0

BUILDLINK_PKGSRCDIR.superlu?=	../../math/superlu
BUILDLINK_DEPMETHOD.superlu?=	build
.endif # SUPERLU_BUILDLINK3_MK

BUILDLINK_TREE+=	-superlu
