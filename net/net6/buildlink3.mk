# $NetBSD: buildlink3.mk,v 1.15 2022/10/26 10:31:06 wiz Exp $

BUILDLINK_TREE+=	net6

.if !defined(NET6_BUILDLINK3_MK)
NET6_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.net6+=	net6>=1.3.5
BUILDLINK_ABI_DEPENDS.net6+=	net6>=1.3.14nb11
BUILDLINK_PKGSRCDIR.net6?=	../../net/net6

.include "../../devel/libsigc++/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.endif # NET6_BUILDLINK3_MK

BUILDLINK_TREE+=	-net6
