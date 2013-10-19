# $NetBSD: buildlink3.mk,v 1.25 2013/10/19 09:06:56 adam Exp $

BUILDLINK_TREE+=	libchamplain

.if !defined(LIBCHAMPLAIN_BUILDLINK3_MK)
LIBCHAMPLAIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libchamplain+=	libchamplain04>=0.4.6
BUILDLINK_ABI_DEPENDS.libchamplain+=	libchamplain04>=0.4.7nb18
BUILDLINK_PKGSRCDIR.libchamplain?=	../../geography/libchamplain04

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/clutter-gtk/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.endif	# LIBCHAMPLAIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libchamplain
