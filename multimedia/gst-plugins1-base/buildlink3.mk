# $NetBSD: buildlink3.mk,v 1.5 2023/08/14 05:24:55 wiz Exp $

BUILDLINK_TREE+=	gst-plugins1-base

.if !defined(GST_PLUGINS1_BASE_BUILDLINK3_MK)
GST_PLUGINS1_BASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gst-plugins1-base+=	gst-plugins1-base>=1.0.0
BUILDLINK_ABI_DEPENDS.gst-plugins1-base+=	gst-plugins1-base>=1.22.4nb1
BUILDLINK_PKGSRCDIR.gst-plugins1-base?=		../../multimedia/gst-plugins1-base

.include "../../multimedia/gstreamer1/buildlink3.mk"
.endif # GST_PLUGINS1_BASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-gst-plugins1-base
