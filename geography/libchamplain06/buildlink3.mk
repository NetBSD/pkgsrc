# $NetBSD: buildlink3.mk,v 1.55 2020/03/08 16:47:44 wiz Exp $

BUILDLINK_TREE+=	libchamplain06

.if !defined(LIBCHAMPLAIN06_BUILDLINK3_MK)
LIBCHAMPLAIN06_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libchamplain06+=	libchamplain06>=0.6.1
BUILDLINK_ABI_DEPENDS.libchamplain06+=	libchamplain06>=0.6.1nb54
BUILDLINK_PKGSRCDIR.libchamplain06?=	../../geography/libchamplain06

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/clutter-gtk0.10/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.endif	# LIBCHAMPLAIN06_BUILDLINK3_MK

BUILDLINK_TREE+=	-libchamplain06
