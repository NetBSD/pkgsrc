# $NetBSD: buildlink3.mk,v 1.1.1.1 2014/03/05 05:25:18 agc Exp $

BUILDLINK_TREE+=	libmerkletree

.if !defined(LIBMERKLETREE_BUILDLINK3_MK)
LIBMERKLETREE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmerkletree+=	libmerkletree>=20140303
BUILDLINK_PKGSRCDIR.libmerkletree?=	../../security/libmerkletree

.endif	# LIBMERKLETREE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmerkletree
