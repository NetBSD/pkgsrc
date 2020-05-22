# $NetBSD: buildlink3.mk,v 1.9 2020/05/22 08:01:51 adam Exp $

BUILDLINK_TREE+=	nettle

.if !defined(NETTLE_BUILDLINK3_MK)
NETTLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nettle+=	nettle>=2.4
BUILDLINK_ABI_DEPENDS.nettle+=	nettle>=3.6
BUILDLINK_PKGSRCDIR.nettle?=	../../security/nettle

BUILDLINK_API_DEPENDS.gmp+=	gmp>=6.0
.include "../../devel/gmp/buildlink3.mk"
.endif # NETTLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-nettle
