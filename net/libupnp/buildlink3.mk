# $NetBSD: buildlink3.mk,v 1.4 2012/04/13 23:38:34 obache Exp $

BUILDLINK_TREE+=	libupnp

.if !defined(LIBUPNP_BUILDLINK3_MK)
LIBUPNP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libupnp+=	libupnp>=1.4.6
BUILDLINK_ABI_DEPENDS.libupnp+=	libupnp>=1.6.14
BUILDLINK_PKGSRCDIR.libupnp?=	../../net/libupnp
.endif # LIBUPNP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libupnp
