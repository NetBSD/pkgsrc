# $NetBSD: buildlink3.mk,v 1.15 2015/06/07 14:03:20 youri Exp $

BUILDLINK_TREE+=	libsoup

.if !defined(LIBSOUP_BUILDLINK3_MK)
LIBSOUP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsoup+=	libsoup>=2.50.0
BUILDLINK_PKGSRCDIR.libsoup?=	../../net/libsoup

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif	# LIBSOUP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsoup
