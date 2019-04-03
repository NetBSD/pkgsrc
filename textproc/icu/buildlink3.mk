# $NetBSD: buildlink3.mk,v 1.38 2019/04/03 00:12:59 ryoon Exp $

BUILDLINK_TREE+=	icu

.if !defined(ICU_BUILDLINK3_MK)
ICU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.icu+=	icu>=3.4
BUILDLINK_ABI_DEPENDS.icu+=	icu>=64.1
BUILDLINK_PKGSRCDIR.icu?=	../../textproc/icu
.endif # ICU_BUILDLINK3_MK

BUILDLINK_TREE+=	-icu
