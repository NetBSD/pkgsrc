# $NetBSD: buildlink3.mk,v 1.43 2020/11/06 04:05:57 gutteridge Exp $

BUILDLINK_TREE+=	icu

.if !defined(ICU_BUILDLINK3_MK)
ICU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.icu+=	icu>=3.4
BUILDLINK_ABI_DEPENDS.icu+=	icu>=68.1
BUILDLINK_PKGSRCDIR.icu?=	../../textproc/icu

GCC_REQD+=		4.9
.endif # ICU_BUILDLINK3_MK

BUILDLINK_TREE+=	-icu
