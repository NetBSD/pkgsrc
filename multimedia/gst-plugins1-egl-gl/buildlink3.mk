# $NetBSD: buildlink3.mk,v 1.1 2015/01/30 11:09:45 jmcneill Exp $

BUILDLINK_TREE+=	gst-plugins1-gl

.if !defined(GST_PLUGINS1_GL_BUILDLINK3_MK)
GST_PLUGINS1_GL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gst-plugins1-gl+=	gst-plugins1-gl>=1.4.5
BUILDLINK_PKGSRCDIR.gst-plugins1-gl?=	../../multimedia/gst-plugins1-egl-gl

.endif	# GST_PLUGINS1_GL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gst-plugins1-gl
