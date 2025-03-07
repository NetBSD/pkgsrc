# $NetBSD: buildlink3.mk,v 1.1 2025/03/07 12:39:35 pho Exp $

BUILDLINK_TREE+=	hs-chart

.if !defined(HS_CHART_BUILDLINK3_MK)
HS_CHART_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-chart+=	hs-chart>=1.9.5
BUILDLINK_ABI_DEPENDS.hs-chart+=	hs-chart>=1.9.5
BUILDLINK_PKGSRCDIR.hs-chart?=		../../graphics/hs-chart

.include "../../devel/hs-old-locale/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-colour/buildlink3.mk"
.include "../../devel/hs-data-default-class/buildlink3.mk"
.include "../../devel/hs-operational/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_CHART_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-chart
