# $NetBSD: buildlink3.mk,v 1.2 2021/04/24 05:01:28 pho Exp $

BUILDLINK_TREE+=	hs-tabular

.if !defined(HS_TABULAR_BUILDLINK3_MK)
HS_TABULAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tabular+=	hs-tabular>=0.2.2
BUILDLINK_ABI_DEPENDS.hs-tabular+=	hs-tabular>=0.2.2.8
BUILDLINK_PKGSRCDIR.hs-tabular?=	../../devel/hs-tabular
.endif	# HS_TABULAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tabular
