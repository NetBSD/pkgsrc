# $NetBSD: buildlink3.mk,v 1.3 2012/07/09 04:50:12 chs Exp $

BUILDLINK_TREE+=	libnettle

.if !defined(LIBNETTLE_BUILDLINK3_MK)
LIBNETTLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnettle+=	nettle>=2.4
BUILDLINK_PKGSRCDIR.libnettle?=		../../security/nettle

.include "../../devel/gmp/buildlink3.mk"
.endif # LIBNETTLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnettle
