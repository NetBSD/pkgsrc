# $NetBSD: buildlink3.mk,v 1.5 2012/05/07 01:53:33 dholland Exp $

BUILDLINK_TREE+=	gdk-pixbuf2-xlib

.if !defined(GDK_PIXBUF2_XLIB_BUILDLINK3_MK)
GDK_PIXBUF2_XLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gdk-pixbuf2-xlib+=	gdk-pixbuf2-xlib>=2.22.1
BUILDLINK_ABI_DEPENDS.gdk-pixbuf2-xlib+=	gdk-pixbuf2-xlib>=2.24.1nb2
BUILDLINK_PKGSRCDIR.gdk-pixbuf2-xlib?=	../../graphics/gdk-pixbuf2-xlib

.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif	# GDK_PIXBUF2_XLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-gdk-pixbuf2-xlib
