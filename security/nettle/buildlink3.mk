# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/04/26 08:59:33 adam Exp $

BUILDLINK_TREE+=	libnettle

.if !defined(LIBNETTLE_BUILDLINK3_MK)
LIBNETTLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnettle+=	nettle>=2.1
BUILDLINK_PKGSRCDIR.libnettle?=		../../security/nettle
.endif # LIBNETTLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnettle
