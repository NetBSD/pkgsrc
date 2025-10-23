# $NetBSD: buildlink3.mk,v 1.8 2025/10/23 20:38:33 wiz Exp $

BUILDLINK_TREE+=	gst-plugins1-good

.if !defined(GST_PLUGINS1_GOOD_BUILDLINK3_MK)
GST_PLUGINS1_GOOD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gst-plugins1-good+=	gst-plugins1-good>=1.18.4
BUILDLINK_ABI_DEPENDS.gst-plugins1-good+=	gst-plugins1-good>=1.26.5nb2
BUILDLINK_PKGSRCDIR.gst-plugins1-good?=		../../multimedia/gst-plugins1-good

.include "../../multimedia/gstreamer1/buildlink3.mk"
.endif # GST_PLUGINS1_GOOD_BUILDLINK3_MK

BUILDLINK_TREE+=	-gst-plugins1-good
