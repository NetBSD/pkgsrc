# $NetBSD: buildlink3.mk,v 1.17 2013/07/06 16:20:52 ryoon Exp $

BUILDLINK_TREE+=	gupnp-av

.if !defined(GUPNP_AV_BUILDLINK3_MK)
GUPNP_AV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gupnp-av+=	gupnp-av>=0.12.2
BUILDLINK_ABI_DEPENDS.gupnp-av+=	gupnp-av>=0.12.2
BUILDLINK_PKGSRCDIR.gupnp-av?=	../../net/gupnp-av

.include "../../net/gupnp/buildlink3.mk"
.endif	# GUPNP_AV_BUILDLINK3_MK

BUILDLINK_TREE+=	-gupnp-av
