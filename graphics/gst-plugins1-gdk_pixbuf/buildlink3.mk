# $NetBSD: buildlink3.mk,v 1.6 2023/01/03 17:36:24 wiz Exp $

BUILDLINK_TREE+=	gst-plugins1-gdk_pixbuf

.if !defined(GST_PLUGINS1_GDK_PIXBUF_BUILDLINK3_MK)
GST_PLUGINS1_GDK_PIXBUF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gst-plugins1-gdk_pixbuf+=	gst-plugins1-gdk_pixbuf>=1.18.0
BUILDLINK_ABI_DEPENDS.gst-plugins1-gdk_pixbuf+=	gst-plugins1-gdk_pixbuf>=1.20.4nb1
BUILDLINK_PKGSRCDIR.gst-plugins1-gdk_pixbuf?=	../../graphics/gst-plugins1-gdk_pixbuf

.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.endif	# GST_PLUGINS1_GDK_PIXBUF_BUILDLINK3_MK

BUILDLINK_TREE+=	-gst-plugins1-gdk_pixbuf
