# $NetBSD: buildlink3.mk,v 1.1 2012/10/11 11:23:11 drochner Exp $

BUILDLINK_TREE+=	gupnp-vala

.if !defined(GUPNP_VALA_BUILDLINK3_MK)
GUPNP_VALA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gupnp-vala+=	gupnp-vala>=0.5.3
BUILDLINK_PKGSRCDIR.gupnp-vala?=	../../net/gupnp-vala

#.include "../../lang/vala018/buildlink3.mk"
#.include "../../net/gssdp/buildlink3.mk"
#.include "../../net/gupnp/buildlink3.mk"
#.include "../../net/gupnp-ui/buildlink3.mk"
#.include "../../net/gupnp-av/buildlink3.mk"
.endif	# GUPNP_VALA_BUILDLINK3_MK

BUILDLINK_TREE+=	-gupnp-vala
