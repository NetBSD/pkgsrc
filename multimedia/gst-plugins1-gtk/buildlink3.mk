# $NetBSD: buildlink3.mk,v 1.9 2022/08/11 05:09:05 gutteridge Exp $

BUILDLINK_TREE+=	gst-plugins1-gtk

.if !defined(GST_PLUGINS1_GTK_BUILDLINK3_MK)
GST_PLUGINS1_GTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gst-plugins1-gtk+=	gst-plugins1-gtk>=1.16.0
BUILDLINK_ABI_DEPENDS.gst-plugins1-gtk?=	gst-plugins1-gtk>=1.20.3nb1
BUILDLINK_PKGSRCDIR.gst-plugins1-gtk?=		../../multimedia/gst-plugins1-gtk

.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# GST_PLUGINS1_GTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-gst-plugins1-gtk
