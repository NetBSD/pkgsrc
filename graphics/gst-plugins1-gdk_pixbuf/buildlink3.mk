# $NetBSD: buildlink3.mk,v 1.1 2019/10/03 14:58:08 nia Exp $

BUILDLINK_TREE+=	gst-plugins1-gdk_pixbuf

.if !defined(GST_PLUGINS1_GDK_PIXBUF_BUILDLINK3_MK)
GST_PLUGINS1_GDK_PIXBUF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gst-plugins1-gdk_pixbuf+=	gst-plugins1-gdk_pixbuf>=1.16.0
BUILDLINK_PKGSRCDIR.gst-plugins1-gdk_pixbuf?=	../../graphics/gst-plugins1-gdk_pixbuf

.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.endif	# GST_PLUGINS1_GDK_PIXBUF_BUILDLINK3_MK

BUILDLINK_TREE+=	-gst-plugins1-gdk_pixbuf
