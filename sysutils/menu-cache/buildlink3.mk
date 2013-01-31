# $NetBSD: buildlink3.mk,v 1.1 2013/01/31 03:25:53 reed Exp $

BUILDLINK_TREE+=	menu-cache

.if !defined(MENU_CACHE_BUILDLINK3_MK)
MENU_CACHE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.menu-cache+=	menu-cache>=0.2.3
BUILDLINK_PKGSRCDIR.menu-cache?=	../../sysutils/menu-cache

.endif	# MENU_CACHE_BUILDLINK3_MK

BUILDLINK_TREE+=	-menu-cache
