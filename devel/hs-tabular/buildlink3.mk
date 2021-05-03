# $NetBSD: buildlink3.mk,v 1.3 2021/05/03 19:01:03 pho Exp $

BUILDLINK_TREE+=	hs-tabular

.if !defined(HS_TABULAR_BUILDLINK3_MK)
HS_TABULAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tabular+=	hs-tabular>=0.2.2
BUILDLINK_ABI_DEPENDS.hs-tabular+=	hs-tabular>=0.2.2.8nb1
BUILDLINK_PKGSRCDIR.hs-tabular?=	../../devel/hs-tabular
.endif	# HS_TABULAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tabular
