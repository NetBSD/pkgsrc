# $NetBSD: buildlink3.mk,v 1.15 2012/10/02 17:11:05 tron Exp $

BUILDLINK_TREE+=	libchamplain

.if !defined(LIBCHAMPLAIN_BUILDLINK3_MK)
LIBCHAMPLAIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libchamplain+=	libchamplain04>=0.4.6
BUILDLINK_ABI_DEPENDS.libchamplain+=	libchamplain04>=0.4.7nb7
BUILDLINK_PKGSRCDIR.libchamplain?=	../../geography/libchamplain04

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/clutter-gtk/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.endif	# LIBCHAMPLAIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libchamplain
