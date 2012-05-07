# $NetBSD: buildlink3.mk,v 1.8 2012/05/07 01:53:52 dholland Exp $

BUILDLINK_TREE+=	libdnet

.if !defined(LIBDNET_BUILDLINK3_MK)
LIBDNET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdnet+=	libdnet>=1.7
BUILDLINK_ABI_DEPENDS.libdnet+=	libdnet>=1.10nb1
BUILDLINK_PKGSRCDIR.libdnet?=	../../net/libdnet
.endif # LIBDNET_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdnet
