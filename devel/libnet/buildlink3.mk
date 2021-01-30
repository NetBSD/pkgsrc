# $NetBSD: buildlink3.mk,v 1.9 2021/01/30 08:23:18 jperkin Exp $

BUILDLINK_TREE+=	libnet

.if !defined(LIBNET_BUILDLINK3_MK)
LIBNET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnet+=		libnet>=1.2
BUILDLINK_PKGSRCDIR.libnet?=		../../devel/libnet
.endif

BUILDLINK_TREE+=	-libnet
