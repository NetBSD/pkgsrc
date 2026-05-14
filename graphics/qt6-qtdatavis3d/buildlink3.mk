# $NetBSD: buildlink3.mk,v 1.22 2026/05/14 16:41:16 ryoon Exp $

BUILDLINK_TREE+=	qt6-qtdatavis3d

.if !defined(QT6_QTDATAVIS3D_BUILDLINK3_MK)
QT6_QTDATAVIS3D_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtdatavis3d+=	qt6-qtdatavis3d>=6.4.1
BUILDLINK_ABI_DEPENDS.qt6-qtdatavis3d+=	qt6-qtdatavis3d>=6.11.1nb1
BUILDLINK_PKGSRCDIR.qt6-qtdatavis3d?=	../../graphics/qt6-qtdatavis3d

.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../multimedia/qt6-qtmultimedia/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QT6_QTDATAVIS3D_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtdatavis3d
