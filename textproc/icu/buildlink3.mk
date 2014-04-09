# $NetBSD: buildlink3.mk,v 1.25 2014/04/09 07:26:56 obache Exp $

BUILDLINK_TREE+=	icu

.if !defined(ICU_BUILDLINK3_MK)
ICU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.icu+=	icu>=3.4
BUILDLINK_ABI_DEPENDS.icu+=	icu>=53.1
BUILDLINK_PKGSRCDIR.icu?=	../../textproc/icu
.endif # ICU_BUILDLINK3_MK

BUILDLINK_TREE+=	-icu
