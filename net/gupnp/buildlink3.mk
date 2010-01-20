# $NetBSD: buildlink3.mk,v 1.3 2010/01/20 14:04:53 wiz Exp $

BUILDLINK_TREE+=	gupnp

.if !defined(GUPNP_BUILDLINK3_MK)
GUPNP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gupnp+=	gupnp>=0.13.2
BUILDLINK_ABI_DEPENDS.gupnp?=	gupnp>=0.13.2
BUILDLINK_PKGSRCDIR.gupnp?=	../../net/gupnp

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../net/gssdp/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif	# GUPNP_BUILDLINK3_MK

BUILDLINK_TREE+=	-gupnp
