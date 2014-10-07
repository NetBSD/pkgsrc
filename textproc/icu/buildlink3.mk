# $NetBSD: buildlink3.mk,v 1.26 2014/10/07 16:47:14 adam Exp $

BUILDLINK_TREE+=	icu

.if !defined(ICU_BUILDLINK3_MK)
ICU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.icu+=	icu>=3.4
BUILDLINK_ABI_DEPENDS.icu+=	icu>=54.1nb1
BUILDLINK_PKGSRCDIR.icu?=	../../textproc/icu
.endif # ICU_BUILDLINK3_MK

BUILDLINK_TREE+=	-icu
