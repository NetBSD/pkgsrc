# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:02 joerg Exp $

BUILDLINK_TREE+=	gst-gnonlin

.if !defined(GST_GNONLIN_BUILDLINK3_MK)
GST_GNONLIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gst-gnonlin+=	gst-gnonlin>=0.10.6
BUILDLINK_PKGSRCDIR.gst-gnonlin?=	../../multimedia/gst-plugins0.10-gnonlin
.endif # GST_GNONLIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-gst-gnonlin
