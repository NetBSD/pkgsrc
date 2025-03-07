# $NetBSD: buildlink3.mk,v 1.1 2025/03/07 16:44:03 pho Exp $

BUILDLINK_TREE+=	hs-chart-cairo

.if !defined(HS_CHART_CAIRO_BUILDLINK3_MK)
HS_CHART_CAIRO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-chart-cairo+=	hs-chart-cairo>=1.9.4
BUILDLINK_ABI_DEPENDS.hs-chart-cairo+=	hs-chart-cairo>=1.9.4.1
BUILDLINK_PKGSRCDIR.hs-chart-cairo?=	../../graphics/hs-chart-cairo

.include "../../devel/hs-old-locale/buildlink3.mk"
.include "../../graphics/hs-cairo/buildlink3.mk"
.include "../../devel/hs-colour/buildlink3.mk"
.include "../../devel/hs-data-default-class/buildlink3.mk"
.include "../../devel/hs-operational/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../graphics/hs-chart/buildlink3.mk"
.endif	# HS_CHART_CAIRO_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-chart-cairo
