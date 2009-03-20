# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:24:59 joerg Exp $

BUILDLINK_TREE+=	superlu

.if !defined(SUPERLU_BUILDLINK3_MK)
SUPERLU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.superlu+=	superlu>=2.0nb2
BUILDLINK_PKGSRCDIR.superlu?=	../../math/superlu
BUILDLINK_DEPMETHOD.superlu?=	build
.endif # SUPERLU_BUILDLINK3_MK

BUILDLINK_TREE+=	-superlu
