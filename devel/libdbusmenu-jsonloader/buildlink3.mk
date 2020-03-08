# $NetBSD: buildlink3.mk,v 1.2 2020/03/08 16:47:36 wiz Exp $

BUILDLINK_TREE+=	libdbusmenu-jsonloader

.if !defined(LIBDBUSMENU_JSONLOADER_BUILDLINK3_MK)
LIBDBUSMENU_JSONLOADER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdbusmenu-jsonloader+=	libdbusmenu-jsonloader>=12.10.2
BUILDLINK_ABI_DEPENDS.libdbusmenu-jsonloader?=	libdbusmenu-jsonloader>=12.10.2nb8
BUILDLINK_PKGSRCDIR.libdbusmenu-jsonloader?=	../../devel/libdbusmenu-jsonloader

.include "../../devel/libdbusmenu-glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.endif	# LIBDBUSMENU_JSONLOADER_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdbusmenu-jsonloader
