# $NetBSD: buildlink3.mk,v 1.4 2015/08/23 14:30:36 wiz Exp $

BUILDLINK_TREE+=	libnettle

.if !defined(LIBNETTLE_BUILDLINK3_MK)
LIBNETTLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnettle+=	nettle>=2.4
BUILDLINK_ABI_DEPENDS.libnettle?=	nettle>=3.1.1
BUILDLINK_PKGSRCDIR.libnettle?=		../../security/nettle

.include "../../devel/gmp/buildlink3.mk"
.endif # LIBNETTLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnettle
