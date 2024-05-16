# $NetBSD: buildlink3.mk,v 1.7 2024/05/16 06:15:21 wiz Exp $

BUILDLINK_TREE+=	libnpupnp

.if !defined(LIBNPUPNP_BUILDLINK3_MK)
LIBNPUPNP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnpupnp+=	libnpupnp>=4.1.5
BUILDLINK_ABI_DEPENDS.libnpupnp?=		libnpupnp>=4.1.5nb6
BUILDLINK_PKGSRCDIR.libnpupnp?=		../../net/libnpupnp

.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../www/libmicrohttpd/buildlink3.mk"
.endif	# LIBNPUPNP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnpupnp
