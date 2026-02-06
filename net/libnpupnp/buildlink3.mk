# $NetBSD: buildlink3.mk,v 1.15 2026/02/06 10:05:34 wiz Exp $

BUILDLINK_TREE+=	libnpupnp

.if !defined(LIBNPUPNP_BUILDLINK3_MK)
LIBNPUPNP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnpupnp+=	libnpupnp>=4.1.5
BUILDLINK_ABI_DEPENDS.libnpupnp?=		libnpupnp>=4.1.5nb15
BUILDLINK_PKGSRCDIR.libnpupnp?=		../../net/libnpupnp

.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../www/libmicrohttpd/buildlink3.mk"
.endif	# LIBNPUPNP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnpupnp
