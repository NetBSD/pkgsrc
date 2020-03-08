# $NetBSD: buildlink3.mk,v 1.23 2020/03/08 16:48:02 wiz Exp $

BUILDLINK_TREE+=	gupnp-dlna

.if !defined(GUPNP_DLNA_BUILDLINK3_MK)
GUPNP_DLNA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gupnp-dlna+=	gupnp-dlna>=0.10.2
BUILDLINK_ABI_DEPENDS.gupnp-dlna?=	gupnp-dlna>=0.10.3nb13
BUILDLINK_PKGSRCDIR.gupnp-dlna?=	../../net/gupnp-dlna

.include "../../net/gupnp/buildlink3.mk"
#.include "../../textproc/libxml2/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.endif	# GUPNP_DLNA_BUILDLINK3_MK

BUILDLINK_TREE+=	-gupnp-dlna
