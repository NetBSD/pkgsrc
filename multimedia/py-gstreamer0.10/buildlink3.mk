# $NetBSD: buildlink3.mk,v 1.3 2009/04/03 12:28:26 drochner Exp $

BUILDLINK_TREE+=	gst-python

.if !defined(GST_PYTHON_BUILDLINK3_MK)
GST_PYTHON_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.gst-python+=	${PYPKGPREFIX}-gstreamer0.10>=0.10.5
BUILDLINK_PKGSRCDIR.gst-python?=	../../multimedia/py-gstreamer0.10
.endif # GST_PYTHON_BUILDLINK3_MK

BUILDLINK_TREE+=	-gst-python
