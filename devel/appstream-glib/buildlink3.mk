# $NetBSD: buildlink3.mk,v 1.4 2023/08/14 05:24:03 wiz Exp $

BUILDLINK_TREE+=	appstream-glib

.if !defined(APPSTREAM_GLIB_BUILDLINK3_MK)
APPSTREAM_GLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.appstream-glib+=	appstream-glib>=0.7.17
BUILDLINK_ABI_DEPENDS.appstream-glib?=	appstream-glib>=0.8.2nb1
BUILDLINK_PKGSRCDIR.appstream-glib?=	../../devel/appstream-glib

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.endif	# APPSTREAM_GLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-appstream-glib
