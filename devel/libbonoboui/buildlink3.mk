# $NetBSD: buildlink3.mk,v 1.71 2022/08/11 05:08:11 gutteridge Exp $

BUILDLINK_TREE+=	libbonoboui

.if !defined(LIBBONOBOUI_BUILDLINK3_MK)
LIBBONOBOUI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libbonoboui+=	libbonoboui>=2.8.0
BUILDLINK_ABI_DEPENDS.libbonoboui+=	libbonoboui>=2.24.5nb7
BUILDLINK_PKGSRCDIR.libbonoboui?=	../../devel/libbonoboui

.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # LIBBONOBOUI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libbonoboui
