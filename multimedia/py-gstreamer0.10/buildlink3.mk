# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:05 joerg Exp $

BUILDLINK_TREE+=	gst-python

.if !defined(GST_PYTHON_BUILDLINK3_MK)
GST_PYTHON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gst-python+=	gst-python>=0.10.5
BUILDLINK_PKGSRCDIR.gst-python?=	../../multimedia/py-gstreamer0.10
.endif # GST_PYTHON_BUILDLINK3_MK

BUILDLINK_TREE+=	-gst-python
