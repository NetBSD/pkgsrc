# $NetBSD: buildlink3.mk,v 1.47 2024/11/01 12:53:53 wiz Exp $

BUILDLINK_TREE+=	gupnp-av

.if !defined(GUPNP_AV_BUILDLINK3_MK)
GUPNP_AV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gupnp-av+=	gupnp-av>=0.12.2
BUILDLINK_ABI_DEPENDS.gupnp-av+=	gupnp-av>=0.14.1nb5
BUILDLINK_PKGSRCDIR.gupnp-av?=		../../net/gupnp-av

.include "../../net/gupnp/buildlink3.mk"
.endif	# GUPNP_AV_BUILDLINK3_MK

BUILDLINK_TREE+=	-gupnp-av
