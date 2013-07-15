# $NetBSD: buildlink3.mk,v 1.24 2013/07/15 02:06:54 obache Exp $
#

BUILDLINK_TREE+=	clutter-gst

.if !defined(CLUTTER_GST_BUILDLINK3_MK)
CLUTTER_GST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.clutter-gst+=	clutter-gst>=2.0.0
BUILDLINK_PKGSRCDIR.clutter-gst?=	../../multimedia/clutter-gst

.include "../../graphics/clutter/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.endif # CLUTTER_GST_BUILDLINK3_MK

BUILDLINK_TREE+=	-clutter-gst
