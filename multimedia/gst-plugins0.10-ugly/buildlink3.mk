# $NetBSD: buildlink3.mk,v 1.12 2020/03/08 16:47:58 wiz Exp $

BUILDLINK_TREE+=	gst-plugins0.10-ugly

.if !defined(GST_PLUGINS0.10_UGLY_BUILDLINK3_MK)
GST_PLUGINS0.10_UGLY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gst-plugins0.10-ugly+=	gst-plugins0.10-ugly>=0.10.3
BUILDLINK_ABI_DEPENDS.gst-plugins0.10-ugly+=	gst-plugins0.10-ugly>=0.10.19nb4
BUILDLINK_PKGSRCDIR.gst-plugins0.10-ugly?=	../../multimedia/gst-plugins0.10-ugly

.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.endif # GST_PLUGINS0.10_UGLY_BUILDLINK3_MK

BUILDLINK_TREE+=	-gst-plugins0.10-ugly
