# $NetBSD: buildlink3.mk,v 1.5 2023/01/29 21:14:50 ryoon Exp $

BUILDLINK_TREE+=	kquickcharts

.if !defined(KQUICKCHARTS_BUILDLINK3_MK)
KQUICKCHARTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kquickcharts+=	kquickcharts>=5.80.0
BUILDLINK_ABI_DEPENDS.kquickcharts?=	kquickcharts>=5.98.0nb2
BUILDLINK_PKGSRCDIR.kquickcharts?=	../../misc/kquickcharts

.include "../../x11/qt5-qtquickcontrols2/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KQUICKCHARTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kquickcharts
