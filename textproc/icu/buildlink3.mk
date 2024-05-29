# $NetBSD: buildlink3.mk,v 1.53 2024/05/29 18:47:07 gutteridge Exp $

BUILDLINK_TREE+=	icu

.if !defined(ICU_BUILDLINK3_MK)
ICU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.icu+=	icu>=3.4
BUILDLINK_ABI_DEPENDS.icu+=	icu>=75.1
BUILDLINK_PKGSRCDIR.icu?=	../../textproc/icu

GCC_REQD+=		4.9
.endif # ICU_BUILDLINK3_MK

BUILDLINK_TREE+=	-icu
