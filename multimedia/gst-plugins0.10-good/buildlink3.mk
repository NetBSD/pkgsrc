# $NetBSD: buildlink3.mk,v 1.19 2022/04/18 19:09:59 adam Exp $

BUILDLINK_TREE+=	gst-plugins0.10-good

.if !defined(GST_PLUGINS0.10_GOOD_BUILDLINK3_MK)
GST_PLUGINS0.10_GOOD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gst-plugins0.10-good+=	gst-plugins0.10-good>=0.10.1
BUILDLINK_ABI_DEPENDS.gst-plugins0.10-good+=	gst-plugins0.10-good>=0.10.31nb10
BUILDLINK_PKGSRCDIR.gst-plugins0.10-good?=	../../multimedia/gst-plugins0.10-good

.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.endif # GST_PLUGINS0.10_GOOD_BUILDLINK3_MK

BUILDLINK_TREE+=	-gst-plugins0.10-good
