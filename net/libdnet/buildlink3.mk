# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:25:09 joerg Exp $

BUILDLINK_TREE+=	libdnet

.if !defined(LIBDNET_BUILDLINK3_MK)
LIBDNET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdnet+=	libdnet>=1.7
BUILDLINK_ABI_DEPENDS.libdnet?=	libdnet>=1.10nb1
BUILDLINK_PKGSRCDIR.libdnet?=	../../net/libdnet
.endif # LIBDNET_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdnet
