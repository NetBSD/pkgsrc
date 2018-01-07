# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:04:24 rillig Exp $

BUILDLINK_TREE+=	gst-plugins1-good

.if !defined(GST_PLUGINS1_GOOD_BUILDLINK3_MK)
GST_PLUGINS1_GOOD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gst-plugins1-good+=	gst-plugins1-good>=1.0.3
BUILDLINK_ABI_DEPENDS.gst-plugins1-good+=	gst-plugins1-good>=1.0.3
BUILDLINK_PKGSRCDIR.gst-plugins1-good?=		../../multimedia/gst-plugins1-good

.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.endif # GST_PLUGINS1_GOOD_BUILDLINK3_MK

BUILDLINK_TREE+=	-gst-plugins1-good
