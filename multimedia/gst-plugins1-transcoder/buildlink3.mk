# $NetBSD: buildlink3.mk,v 1.4 2023/08/14 05:24:56 wiz Exp $

BUILDLINK_TREE+=	gst-plugins1-transcoder

.if !defined(GST_PLUGINS1_TRANSCODER_BUILDLINK3_MK)
GST_PLUGINS1_TRANSCODER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gst-plugins1-transcoder+=	gst-plugins1-transcoder>=1.16.0
BUILDLINK_ABI_DEPENDS.gst-plugins1-transcoder?=	gst-plugins1-transcoder>=1.16.0nb4
BUILDLINK_PKGSRCDIR.gst-plugins1-transcoder?=	../../multimedia/gst-plugins1-transcoder

.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.endif	# GST_PLUGINS1_TRANSCODER_BUILDLINK3_MK

BUILDLINK_TREE+=	-gst-plugins1-transcoder
