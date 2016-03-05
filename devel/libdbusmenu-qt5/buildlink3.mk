# $NetBSD: buildlink3.mk,v 1.2 2016/03/05 11:27:45 jperkin Exp $

BUILDLINK_TREE+=	libdbusmenu-qt5

.if !defined(LIBDBUSMENU_QT5_BUILDLINK3_MK)
LIBDBUSMENU_QT5_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdbusmenu-qt5+=	libdbusmenu-qt5>=0.9.3.15.10.20150604
BUILDLINK_ABI_DEPENDS.libdbusmenu-qt5?=	libdbusmenu-qt5>=0.9.3.15.10.20150604nb1
BUILDLINK_PKGSRCDIR.libdbusmenu-qt5?=	../../devel/libdbusmenu-qt5

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# LIBDBUSMENU_QT5_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdbusmenu-qt5
