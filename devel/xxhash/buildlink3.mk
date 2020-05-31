# $NetBSD: buildlink3.mk,v 1.2 2020/05/31 09:51:35 nia Exp $

BUILDLINK_TREE+=	xxhash

.if !defined(XXHASH_BUILDLINK3_MK)
XXHASH_BUILDLINK3_MK:=

BUILDLINK_ABI_DEPENDS.xxhash+=	xxhash>=0.7.3
BUILDLINK_API_DEPENDS.xxhash+=	xxhash>=0.7.3
BUILDLINK_PKGSRCDIR.xxhash?=	../../devel/xxhash
.endif # XXHASH_BUILDLINK3_MK

BUILDLINK_TREE+=	-xxhash
