# $NetBSD: buildlink3.mk,v 1.1 2025/08/23 12:44:56 adam Exp $

BUILDLINK_TREE+=	gst-plugins1-gl

.if !defined(GST_PLUGINS1_GL_BUILDLINK3_MK)
GST_PLUGINS1_GL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gst-plugins1-gl+=	gst-plugins1-gl>=1.24.12
BUILDLINK_PKGSRCDIR.gst-plugins1-gl?=	../../graphics/gst-plugins1-gl

.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.endif	# GST_PLUGINS1_GL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gst-plugins1-gl
