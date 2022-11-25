# $NetBSD: buildlink3.mk,v 1.1 2022/11/25 14:27:11 nros Exp $

BUILDLINK_TREE+=	qt6-qtdatavis3d

.if !defined(QT6_QTDATAVIS3D_BUILDLINK3_MK)
QT6_QTDATAVIS3D_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtdatavis3d+=	qt6-qtdatavis3d>=6.4.1
BUILDLINK_PKGSRCDIR.qt6-qtdatavis3d?=	../../graphics/qt6-qtdatavis3d

.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QT6_QTDATAVIS3D_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtdatavis3d
