# $NetBSD: buildlink3.mk,v 1.2 2013/01/26 21:36:40 adam Exp $

BUILDLINK_TREE+=	gupnp-vala

.if !defined(GUPNP_VALA_BUILDLINK3_MK)
GUPNP_VALA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gupnp-vala+=	gupnp-vala>=0.5.3
BUILDLINK_ABI_DEPENDS.gupnp-vala?=	gupnp-vala>=0.10.5nb1
BUILDLINK_PKGSRCDIR.gupnp-vala?=	../../net/gupnp-vala

#.include "../../lang/vala018/buildlink3.mk"
#.include "../../net/gssdp/buildlink3.mk"
#.include "../../net/gupnp/buildlink3.mk"
#.include "../../net/gupnp-ui/buildlink3.mk"
#.include "../../net/gupnp-av/buildlink3.mk"
.endif	# GUPNP_VALA_BUILDLINK3_MK

BUILDLINK_TREE+=	-gupnp-vala
