# $NetBSD: buildlink3.mk,v 1.1 2015/10/07 12:33:16 adam Exp $

BUILDLINK_TREE+=	uthash

.if !defined(UTHASH_BUILDLINK3_MK)
UTHASH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.uthash+=	uthash>=1.9.9
BUILDLINK_PKGSRCDIR.uthash?=	../../devel/uthash
BUILDLINK_DEPMETHOD.uthash?=	build
.endif	# UTHASH_BUILDLINK3_MK

BUILDLINK_TREE+=	-uthash
