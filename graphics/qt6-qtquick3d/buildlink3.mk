# $NetBSD: buildlink3.mk,v 1.1 2022/11/25 20:58:55 nros Exp $

BUILDLINK_TREE+=	qt6-qtquick3d

.if !defined(QT6_QTQUICK3D_BUILDLINK3_MK)
QT6_QTQUICK3D_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qtquick3d+=	qt6-qtquick3d>=6.4.1
BUILDLINK_PKGSRCDIR.qt6-qtquick3d?=	../../graphics/qt6-qtquick3d

.include "../../graphics/qt6-qtshadertools/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QT6_QTQUICK3D_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qtquick3d
