# $NetBSD: buildlink3.mk,v 1.1 2018/09/10 13:47:31 fhajny Exp $

BUILDLINK_TREE+=	xxhash

.if !defined(XXHASH_BUILDLINK3_MK)
XXHASH_BUILDLINK3_MK:=

BUILDLINK_ABI_DEPENDS.xxhash+=	xxhash>=0.6.0
BUILDLINK_API_DEPENDS.xxhash+=	xxhash>=0.6.0
BUILDLINK_PKGSRCDIR.xxhash?=	../../devel/xxhash
.endif # XXHASH_BUILDLINK3_MK

BUILDLINK_TREE+=	-xxhash
