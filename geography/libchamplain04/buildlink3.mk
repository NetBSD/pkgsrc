# $NetBSD: buildlink3.mk,v 1.45 2018/03/12 11:15:32 wiz Exp $

BUILDLINK_TREE+=	libchamplain

.if !defined(LIBCHAMPLAIN_BUILDLINK3_MK)
LIBCHAMPLAIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libchamplain+=	libchamplain04>=0.4.6
BUILDLINK_ABI_DEPENDS.libchamplain+=	libchamplain04>=0.4.7nb38
BUILDLINK_PKGSRCDIR.libchamplain?=	../../geography/libchamplain04

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/clutter-gtk0.10/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.endif	# LIBCHAMPLAIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libchamplain
