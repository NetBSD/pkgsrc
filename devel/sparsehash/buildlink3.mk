# $NetBSD: buildlink3.mk,v 1.1 2012/09/15 17:25:40 dholland Exp $

BUILDLINK_TREE+=	sparsehash

.if !defined(SPARSEHASH_BUILDLINK3_MK)
SPARSEHASH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sparsehash+=	sparsehash>=2.0.2
BUILDLINK_ABI_DEPENDS.sparsehash+=	sparsehash>=2.0.2
BUILDLINK_PKGSRCDIR.sparsehash?=	../../devel/sparsehash
.endif # SPARSEHASH_BUILDLINK3_MK

BUILDLINK_TREE+=	-sparsehash
