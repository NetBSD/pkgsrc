# $NetBSD: buildlink3.mk,v 1.7 2012/06/14 07:43:40 sbd Exp $
#

BUILDLINK_TREE+=	p5-GStreamer

.if !defined(P5_GSTREAMER_BUILDLINK3_MK)
P5_GSTREAMER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.p5-GStreamer+=	p5-GStreamer>=0.11
BUILDLINK_ABI_DEPENDS.p5-GStreamer+=	p5-GStreamer>=0.16nb3
BUILDLINK_PKGSRCDIR.p5-GStreamer?=	../../multimedia/p5-GStreamer

.include "../../devel/p5-glib2/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.endif # P5_GSTREAMER_BUILDLINK3_MK

BUILDLINK_TREE+=	-p5-GStreamer
