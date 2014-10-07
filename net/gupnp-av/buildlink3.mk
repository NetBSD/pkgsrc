# $NetBSD: buildlink3.mk,v 1.21 2014/10/07 16:47:13 adam Exp $

BUILDLINK_TREE+=	gupnp-av

.if !defined(GUPNP_AV_BUILDLINK3_MK)
GUPNP_AV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gupnp-av+=	gupnp-av>=0.12.2
BUILDLINK_ABI_DEPENDS.gupnp-av+=	gupnp-av>=0.12.6nb1
BUILDLINK_PKGSRCDIR.gupnp-av?=	../../net/gupnp-av

.include "../../net/gupnp/buildlink3.mk"
.endif	# GUPNP_AV_BUILDLINK3_MK

BUILDLINK_TREE+=	-gupnp-av
