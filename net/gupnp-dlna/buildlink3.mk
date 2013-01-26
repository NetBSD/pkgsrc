# $NetBSD: buildlink3.mk,v 1.3 2013/01/26 21:36:40 adam Exp $

BUILDLINK_TREE+=	gupnp-dlna

.if !defined(GUPNP_DLNA_BUILDLINK3_MK)
GUPNP_DLNA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gupnp-dlna+=	gupnp-dlna>=0.6.6
BUILDLINK_ABI_DEPENDS.gupnp-dlna?=	gupnp-dlna>=0.6.6nb1
BUILDLINK_PKGSRCDIR.gupnp-dlna?=	../../net/gupnp-dlna

.include "../../net/gupnp/buildlink3.mk"
#.include "../../textproc/libxml2/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.endif	# GUPNP_DLNA_BUILDLINK3_MK

BUILDLINK_TREE+=	-gupnp-dlna
