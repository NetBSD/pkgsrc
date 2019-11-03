# $NetBSD: buildlink3.mk,v 1.2 2019/11/03 17:12:01 rillig Exp $

BUILDLINK_TREE+=	gst-plugins1-gtk

.if !defined(GST_PLUGINS1_GTK_BUILDLINK3_MK)
GST_PLUGINS1_GTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gst-plugins1-gtk+=	gst-plugins1-gtk>=1.16.0
BUILDLINK_PKGSRCDIR.gst-plugins1-gtk?=		../../multimedia/gst-plugins1-gtk

.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# GST_PLUGINS1_GTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-gst-plugins1-gtk
