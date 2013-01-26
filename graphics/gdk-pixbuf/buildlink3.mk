# $NetBSD: buildlink3.mk,v 1.22 2013/01/26 21:36:27 adam Exp $

BUILDLINK_TREE+=	gdk-pixbuf

.if !defined(GDK_PIXBUF_BUILDLINK3_MK)
GDK_PIXBUF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gdk-pixbuf+=		gdk-pixbuf>=0.22.0nb2
BUILDLINK_ABI_DEPENDS.gdk-pixbuf+=	gdk-pixbuf>=0.22.0nb18
BUILDLINK_PKGSRCDIR.gdk-pixbuf?=	../../graphics/gdk-pixbuf
BUILDLINK_CPPFLAGS.gdk-pixbuf+= \
	-I${BUILDLINK_PREFIX.gdk-pixbuf}/include/gdk-pixbuf-1.0

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.endif # GDK_PIXBUF_BUILDLINK3_MK

BUILDLINK_TREE+=	-gdk-pixbuf
