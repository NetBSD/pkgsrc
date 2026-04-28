# $NetBSD: buildlink3.mk,v 1.2 2026/04/28 07:54:39 pin Exp $

BUILDLINK_TREE+=	lxqt-menu-data

.if !defined(LXQT_MENU_DATA_BUILDLINK3_MK)
LXQT_MENU_DATA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lxqt-menu-data+=	lxqt-menu-data>=2.1.0
BUILDLINK_ABI_DEPENDS.lxqt-menu-data?=	lxqt-menu-data>=2.4.0
BUILDLINK_PKGSRCDIR.lxqt-menu-data?=	../../sysutils/lxqt-menu-data

BUILDLINK_FILES.lxqt-menu-data+=	share/cmake/*
.endif	# LXQT_MENU_DATA_BUILDLINK3_MK

BUILDLINK_TREE+=	-lxqt-menu-data
