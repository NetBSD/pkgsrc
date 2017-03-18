# $NetBSD: buildlink3.mk,v 1.2 2017/03/18 20:18:39 adam Exp $

BUILDLINK_TREE+=	libepoxy

.if !defined(LIBEPOXY_BUILDLINK3_MK)
LIBEPOXY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libepoxy+=	libepoxy>=1.2
BUILDLINK_PKGSRCDIR.libepoxy?=		../../graphics/libepoxy

.endif	# LIBEPOXY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libepoxy
