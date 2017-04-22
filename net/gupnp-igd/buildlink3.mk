# $NetBSD: buildlink3.mk,v 1.26 2017/04/22 21:03:14 adam Exp $

BUILDLINK_TREE+=	gupnp-igd

.if !defined(GUPNP_IGD_BUILDLINK3_MK)
GUPNP_IGD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gupnp-igd+=	gupnp-igd>=0.2.1
BUILDLINK_ABI_DEPENDS.gupnp-igd+=	gupnp-igd>=0.2.3nb9
BUILDLINK_PKGSRCDIR.gupnp-igd?=	../../net/gupnp-igd

.include "../../net/gupnp/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif	# GUPNP_IGD_BUILDLINK3_MK

BUILDLINK_TREE+=	-gupnp-igd
