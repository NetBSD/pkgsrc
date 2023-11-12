# $NetBSD: buildlink3.mk,v 1.4 2023/11/12 13:20:52 wiz Exp $

BUILDLINK_TREE+=	qt6-qtconnectivity

.if !defined(QT6_QTCONNECTIVITY_BUILDLINK3_MK)
QT6_QTCONNECTIVITY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtconnectivity+=	qt6-qtconnectivity>=6.5.2
BUILDLINK_ABI_DEPENDS.qt6-qtconnectivity+=	qt6-qtconnectivity>=6.6.0nb2
BUILDLINK_PKGSRCDIR.qt6-qtconnectivity?=	../../comms/qt6-qtconnectivity

.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QT6_QTCONNECTIVITY_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtconnectivity
