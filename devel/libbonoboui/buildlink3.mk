# $NetBSD: buildlink3.mk,v 1.48 2014/05/05 00:47:44 ryoon Exp $

BUILDLINK_TREE+=	libbonoboui

.if !defined(LIBBONOBOUI_BUILDLINK3_MK)
LIBBONOBOUI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libbonoboui+=		libbonoboui>=2.8.0
BUILDLINK_ABI_DEPENDS.libbonoboui+=	libbonoboui>=2.24.4nb24
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
