# $NetBSD: buildlink3.mk,v 1.6 2023/04/19 08:08:31 adam Exp $

BUILDLINK_TREE+=	kquickcharts

.if !defined(KQUICKCHARTS_BUILDLINK3_MK)
KQUICKCHARTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kquickcharts+=	kquickcharts>=5.80.0
BUILDLINK_ABI_DEPENDS.kquickcharts?=	kquickcharts>=5.98.0nb4
BUILDLINK_PKGSRCDIR.kquickcharts?=	../../misc/kquickcharts

.include "../../x11/qt5-qtquickcontrols2/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KQUICKCHARTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kquickcharts
