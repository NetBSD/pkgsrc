# $NetBSD: buildlink3.mk,v 1.15 2026/04/30 06:38:37 adam Exp $

BUILDLINK_TREE+=	qt6-qtconnectivity

.if !defined(QT6_QTCONNECTIVITY_BUILDLINK3_MK)
QT6_QTCONNECTIVITY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtconnectivity+=	qt6-qtconnectivity>=6.5.2
BUILDLINK_ABI_DEPENDS.qt6-qtconnectivity+=	qt6-qtconnectivity>=6.11.0
BUILDLINK_PKGSRCDIR.qt6-qtconnectivity?=	../../comms/qt6-qtconnectivity

.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QT6_QTCONNECTIVITY_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtconnectivity
