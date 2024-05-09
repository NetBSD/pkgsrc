# $NetBSD: buildlink3.mk,v 1.11 2024/05/09 01:32:14 pho Exp $

BUILDLINK_TREE+=	hs-tabular

.if !defined(HS_TABULAR_BUILDLINK3_MK)
HS_TABULAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tabular+=	hs-tabular>=0.2.2
BUILDLINK_ABI_DEPENDS.hs-tabular+=	hs-tabular>=0.2.2.8nb8
BUILDLINK_PKGSRCDIR.hs-tabular?=	../../devel/hs-tabular

.include "../../textproc/hs-csv/buildlink3.mk"
.include "../../textproc/hs-html/buildlink3.mk"
.endif	# HS_TABULAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tabular
