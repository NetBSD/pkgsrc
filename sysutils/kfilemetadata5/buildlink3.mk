# $NetBSD: buildlink3.mk,v 1.2 2023/08/14 05:25:16 wiz Exp $

BUILDLINK_TREE+=	kfilemetadata5

.if !defined(KFILEMETADATA5_BUILDLINK3_MK)
KFILEMETADATA5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kfilemetadata5+=	kfilemetadata5>=5.19.0
BUILDLINK_ABI_DEPENDS.kfilemetadata5?=	kfilemetadata5>=5.108.0nb1
BUILDLINK_PKGSRCDIR.kfilemetadata5?=	../../sysutils/kfilemetadata5

.endif	# KFILEMETADATA5_BUILDLINK3_MK

BUILDLINK_TREE+=	-kfilemetadata5
