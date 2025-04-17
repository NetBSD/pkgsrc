# $NetBSD: buildlink3.mk,v 1.36 2025/04/17 21:50:28 wiz Exp $

BUILDLINK_TREE+=	libdbusmenu-qt5

.if !defined(LIBDBUSMENU_QT5_BUILDLINK3_MK)
LIBDBUSMENU_QT5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdbusmenu-qt5+=	libdbusmenu-qt5>=0.9.3.15.10.20150604
BUILDLINK_ABI_DEPENDS.libdbusmenu-qt5?=	libdbusmenu-qt5>=0.9.3.16.04.20160218nb30
BUILDLINK_PKGSRCDIR.libdbusmenu-qt5?=	../../devel/libdbusmenu-qt5

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# LIBDBUSMENU_QT5_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdbusmenu-qt5
