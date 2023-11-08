# $NetBSD: buildlink3.mk,v 1.6 2023/11/08 13:19:26 wiz Exp $

BUILDLINK_TREE+=	qt6-qtlocation

.if !defined(QT6_QTLOCATION_BUILDLINK3_MK)
QT6_QTLOCATION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtlocation+=	qt6-qtlocation>=6.5.0
BUILDLINK_ABI_DEPENDS.qt6-qtlocation+=	qt6-qtlocation>=6.6.0nb1
BUILDLINK_PKGSRCDIR.qt6-qtlocation?=	../../geography/qt6-qtlocation

.include "../../geography/qt6-qtpositioning/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QT6_QTLOCATION_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtlocation
