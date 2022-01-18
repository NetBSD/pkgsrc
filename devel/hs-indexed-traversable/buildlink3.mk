# $NetBSD: buildlink3.mk,v 1.3 2022/01/18 02:48:09 pho Exp $

BUILDLINK_TREE+=	hs-indexed-traversable

.if !defined(HS_INDEXED_TRAVERSABLE_BUILDLINK3_MK)
HS_INDEXED_TRAVERSABLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-indexed-traversable+=	hs-indexed-traversable>=0.1.1
BUILDLINK_ABI_DEPENDS.hs-indexed-traversable+=	hs-indexed-traversable>=0.1.1nb2
BUILDLINK_PKGSRCDIR.hs-indexed-traversable?=	../../devel/hs-indexed-traversable
.endif	# HS_INDEXED_TRAVERSABLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-indexed-traversable
