# $NetBSD: buildlink3.mk,v 1.9 2026/02/06 10:05:20 wiz Exp $

BUILDLINK_TREE+=	kf6-kquickcharts

.if !defined(KF6_KQUICKCHARTS_BUILDLINK3_MK)
KF6_KQUICKCHARTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kf6-kquickcharts+=	kf6-kquickcharts>=6.2.0
BUILDLINK_ABI_DEPENDS.kf6-kquickcharts?=		kf6-kquickcharts>=6.18.0nb3
BUILDLINK_PKGSRCDIR.kf6-kquickcharts?=		../../misc/kf6-kquickcharts

.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KF6_KQUICKCHARTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kf6-kquickcharts
