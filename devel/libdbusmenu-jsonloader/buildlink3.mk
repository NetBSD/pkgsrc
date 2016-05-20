# $NetBSD: buildlink3.mk,v 1.1 2016/05/20 22:03:46 youri Exp $

BUILDLINK_TREE+=	libdbusmenu-jsonloader

.if !defined(LIBDBUSMENU_JSONLOADER_BUILDLINK3_MK)
LIBDBUSMENU_JSONLOADER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdbusmenu-jsonloader+=	libdbusmenu-jsonloader>=12.10.2
BUILDLINK_PKGSRCDIR.libdbusmenu-jsonloader?=	../../devel/libdbusmenu-jsonloader

.include "../../devel/libdbusmenu-glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.endif	# LIBDBUSMENU_JSONLOADER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdbusmenu-jsonloader
