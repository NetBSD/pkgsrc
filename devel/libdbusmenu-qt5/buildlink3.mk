# $NetBSD: buildlink3.mk,v 1.17 2020/03/08 16:47:37 wiz Exp $

BUILDLINK_TREE+=	libdbusmenu-qt5

.if !defined(LIBDBUSMENU_QT5_BUILDLINK3_MK)
LIBDBUSMENU_QT5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdbusmenu-qt5+=	libdbusmenu-qt5>=0.9.3.15.10.20150604
BUILDLINK_ABI_DEPENDS.libdbusmenu-qt5?=	libdbusmenu-qt5>=0.9.3.16.04.20160218nb8
BUILDLINK_PKGSRCDIR.libdbusmenu-qt5?=	../../devel/libdbusmenu-qt5

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# LIBDBUSMENU_QT5_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdbusmenu-qt5
