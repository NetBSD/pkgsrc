# $NetBSD: buildlink3.mk,v 1.7 2012/03/03 00:11:58 wiz Exp $

BUILDLINK_TREE+=	gupnp-igd

.if !defined(GUPNP_IGD_BUILDLINK3_MK)
GUPNP_IGD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gupnp-igd+=	gupnp-igd>=0.1.3
BUILDLINK_ABI_DEPENDS.gupnp-igd?=	gupnp-igd>=0.1.7nb4
BUILDLINK_PKGSRCDIR.gupnp-igd?=	../../net/gupnp-igd

.include "../../net/gupnp/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif	# GUPNP_IGD_BUILDLINK3_MK

BUILDLINK_TREE+=	-gupnp-igd
