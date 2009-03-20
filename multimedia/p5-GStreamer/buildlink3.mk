# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:05 joerg Exp $
#

BUILDLINK_TREE+=	p5-GStreamer

.if !defined(P5_GSTREAMER_BUILDLINK3_MK)
P5_GSTREAMER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.p5-GStreamer+=	p5-GStreamer>=0.11
BUILDLINK_PKGSRCDIR.p5-GStreamer?=	../../multimedia/p5-GStreamer

.include "../../devel/p5-glib2/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.endif # P5_GSTREAMER_BUILDLINK3_MK

BUILDLINK_TREE+=	-p5-GStreamer
