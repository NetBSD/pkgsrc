# $NetBSD: buildlink3.mk,v 1.1 2012/11/29 08:27:25 ryoon Exp $

BUILDLINK_TREE+=	gst-plugins1-ugly

.if !defined(GST_PLUGINS1_UGLY_BUILDLINK3_MK)
GST_PLUGINS1_UGLY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gst-plugins1-ugly+=	gst-plugins1-ugly>=1.0.3
BUILDLINK_ABI_DEPENDS.gst-plugins1-ugly+=	gst-plugins1-ugly>=1.0.3
BUILDLINK_PKGSRCDIR.gst-plugins1-ugly?=	../../multimedia/gst-plugins1-ugly

.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.endif # GST_PLUGINS1_UGLY_BUILDLINK3_MK

BUILDLINK_TREE+=	-gst-plugins1-ugly
