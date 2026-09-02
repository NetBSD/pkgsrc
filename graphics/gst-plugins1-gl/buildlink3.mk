# $NetBSD: buildlink3.mk,v 1.3 2026/09/02 19:02:40 wiz Exp $

BUILDLINK_TREE+=	gst-plugins1-gl

.if !defined(GST_PLUGINS1_GL_BUILDLINK3_MK)
GST_PLUGINS1_GL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gst-plugins1-gl+=	gst-plugins1-gl>=1.24.12
BUILDLINK_ABI_DEPENDS.gst-plugins1-gl?=	gst-plugins1-gl>=1.28.6nb1
BUILDLINK_PKGSRCDIR.gst-plugins1-gl?=	../../graphics/gst-plugins1-gl

.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.endif	# GST_PLUGINS1_GL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gst-plugins1-gl
