# $NetBSD: buildlink3.mk,v 1.7 2023/08/14 05:24:56 wiz Exp $

BUILDLINK_TREE+=	gst-plugins1-ugly

.if !defined(GST_PLUGINS1_UGLY_BUILDLINK3_MK)
GST_PLUGINS1_UGLY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gst-plugins1-ugly+=	gst-plugins1-ugly>=1.18.4
BUILDLINK_ABI_DEPENDS.gst-plugins1-ugly+=	gst-plugins1-ugly>=1.22.4nb1
BUILDLINK_PKGSRCDIR.gst-plugins1-ugly?=		../../multimedia/gst-plugins1-ugly

.include "../../multimedia/gstreamer1/buildlink3.mk"
.endif # GST_PLUGINS1_UGLY_BUILDLINK3_MK

BUILDLINK_TREE+=	-gst-plugins1-ugly
