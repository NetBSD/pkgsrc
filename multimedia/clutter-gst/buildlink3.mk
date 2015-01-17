# $NetBSD: buildlink3.mk,v 1.29 2015/01/17 14:36:12 prlw1 Exp $
#

BUILDLINK_TREE+=	clutter-gst

.if !defined(CLUTTER_GST_BUILDLINK3_MK)
CLUTTER_GST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.clutter-gst+=	clutter-gst>=2.0.0
BUILDLINK_ABI_DEPENDS.clutter-gst?=	clutter-gst>=2.0.8nb2
BUILDLINK_PKGSRCDIR.clutter-gst?=	../../multimedia/clutter-gst

.include "../../graphics/clutter/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.endif # CLUTTER_GST_BUILDLINK3_MK

BUILDLINK_TREE+=	-clutter-gst
