# $NetBSD: buildlink3.mk,v 1.4 2022/12/16 21:08:08 adam Exp $

BUILDLINK_TREE+=	gst-plugins1-editing-services

.if !defined(GST_PLUGINS1_EDITING_SERVICES_BUILDLINK3_MK)
GST_PLUGINS1_EDITING_SERVICES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gst-plugins1-editing-services+=	gst-plugins1-editing-services>=1.16.0
BUILDLINK_ABI_DEPENDS.gst-plugins1-editing-services+=	gst-plugins1-editing-services>=1.18.5
BUILDLINK_PKGSRCDIR.gst-plugins1-editing-services?=	../../multimedia/gst-plugins1-editing-services

.include "../../multimedia/gstreamer1/buildlink3.mk"
.endif	# GST_PLUGINS1_EDITING_SERVICES_BUILDLINK3_MK

BUILDLINK_TREE+=	-gst-plugins1-editing-services
