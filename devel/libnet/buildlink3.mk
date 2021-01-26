# $NetBSD: buildlink3.mk,v 1.8 2021/01/26 11:20:17 jperkin Exp $

BUILDLINK_TREE+=	libnet

.if !defined(LIBNET_BUILDLINK3_MK)
LIBNET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnet+=		libnet>=1.2
BUILDLINK_PKGSRCDIR.libnet?=		../../devel/libnet
BUILDLINK_DEPMETHOD.libnet?=		build
.endif

BUILDLINK_TREE+=	-libnet
