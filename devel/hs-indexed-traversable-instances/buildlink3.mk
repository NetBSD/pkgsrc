# $NetBSD: buildlink3.mk,v 1.10 2025/01/29 17:41:10 pho Exp $

BUILDLINK_TREE+=	hs-indexed-traversable-instances

.if !defined(HS_INDEXED_TRAVERSABLE_INSTANCES_BUILDLINK3_MK)
HS_INDEXED_TRAVERSABLE_INSTANCES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-indexed-traversable-instances+=	hs-indexed-traversable-instances>=0.1.2
BUILDLINK_ABI_DEPENDS.hs-indexed-traversable-instances+=	hs-indexed-traversable-instances>=0.1.2
BUILDLINK_PKGSRCDIR.hs-indexed-traversable-instances?=		../../devel/hs-indexed-traversable-instances

.include "../../devel/hs-indexed-traversable/buildlink3.mk"
.include "../../devel/hs-OneTuple/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_INDEXED_TRAVERSABLE_INSTANCES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-indexed-traversable-instances
