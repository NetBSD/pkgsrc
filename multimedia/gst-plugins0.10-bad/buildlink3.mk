# $NetBSD: buildlink3.mk,v 1.11 2012/09/15 10:05:47 obache Exp $

BUILDLINK_TREE+=	gst-plugins0.10-bad

.if !defined(GST_PLUGINS0.10_BAD_BUILDLINK3_MK)
GST_PLUGINS0.10_BAD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gst-plugins0.10-bad+=	gst-plugins0.10-bad>=0.10.3
BUILDLINK_ABI_DEPENDS.gst-plugins0.10-bad+=	gst-plugins0.10-bad>=0.10.23nb3
BUILDLINK_PKGSRCDIR.gst-plugins0.10-bad?= ../../multimedia/gst-plugins0.10-bad

.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.endif # GST_PLUGINS0.10_BAD_BUILDLINK3_MK

BUILDLINK_TREE+=	-gst-plugins0.10-bad
