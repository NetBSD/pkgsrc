# $NetBSD: buildlink3.mk,v 1.11 2026/04/28 08:18:40 pin Exp $

BUILDLINK_TREE+=	libdbusmenu-lxqt

.if !defined(LIBDBUSMENU_LXQT_BUILDLINK3_MK)
LIBDBUSMENU_LXQT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdbusmenu-lxqt+=	libdbusmenu-lxqt>=0.2.0
BUILDLINK_ABI_DEPENDS.libdbusmenu-lxqt?=	libdbusmenu-lxqt>=0.4.0
BUILDLINK_PKGSRCDIR.libdbusmenu-lxqt?=	../../devel/libdbusmenu-lxqt

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# LIBDBUSMENU_LXQT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdbusmenu-lxqt
