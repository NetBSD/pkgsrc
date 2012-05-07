# $NetBSD: buildlink3.mk,v 1.7 2012/05/07 01:53:23 dholland Exp $

BUILDLINK_TREE+=	libdnsres

.if !defined(LIBDNSRES_BUILDLINK3_MK)
LIBDNSRES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdnsres+=	libdnsres>=0.1a
BUILDLINK_ABI_DEPENDS.libdnsres+=	libdnsres>=0.1anb4
BUILDLINK_PKGSRCDIR.libdnsres?=	../../devel/libdnsres
.endif # LIBDNSRES_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdnsres
