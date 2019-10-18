# $NetBSD: buildlink3.mk,v 1.1 2019/10/18 18:31:02 nia Exp $

BUILDLINK_TREE+=	gstreamermm

.if !defined(GSTREAMERMM_BUILDLINK3_MK)
GSTREAMERMM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gstreamermm+=	gstreamermm>=1.10.0
BUILDLINK_PKGSRCDIR.gstreamermm?=	../../multimedia/gstreamermm1

.include "../../devel/glibmm/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.endif	# GSTREAMERMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-gstreamermm
