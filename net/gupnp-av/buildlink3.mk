# $NetBSD: buildlink3.mk,v 1.14 2013/01/26 21:36:40 adam Exp $

BUILDLINK_TREE+=	gupnp-av

.if !defined(GUPNP_AV_BUILDLINK3_MK)
GUPNP_AV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gupnp-av+=	gupnp-av>=0.10.3
BUILDLINK_ABI_DEPENDS.gupnp-av+=	gupnp-av>=0.10.3nb1
BUILDLINK_PKGSRCDIR.gupnp-av?=	../../net/gupnp-av

.include "../../net/gupnp/buildlink3.mk"
.endif	# GUPNP_AV_BUILDLINK3_MK

BUILDLINK_TREE+=	-gupnp-av
