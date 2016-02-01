# $NetBSD: buildlink3.mk,v 1.5 2016/02/01 13:27:36 wiz Exp $

BUILDLINK_TREE+=	nettle

.if !defined(NETTLE_BUILDLINK3_MK)
NETTLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nettle+=	nettle>=2.4
BUILDLINK_ABI_DEPENDS.nettle?=	nettle>=3.1.1
BUILDLINK_PKGSRCDIR.nettle?=		../../security/nettle

.include "../../devel/gmp/buildlink3.mk"
.endif # NETTLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-nettle
