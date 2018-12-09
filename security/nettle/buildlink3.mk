# $NetBSD: buildlink3.mk,v 1.7 2018/12/09 20:11:40 leot Exp $

BUILDLINK_TREE+=	nettle

.if !defined(NETTLE_BUILDLINK3_MK)
NETTLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nettle+=	nettle>=2.4
BUILDLINK_ABI_DEPENDS.nettle+=	nettle>=3.1.1
BUILDLINK_PKGSRCDIR.nettle?=	../../security/nettle

BUILDLINK_API_DEPENDS.gmp+=	gmp>=6.0
.include "../../devel/gmp/buildlink3.mk"
.endif # NETTLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-nettle
