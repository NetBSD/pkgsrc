# $NetBSD: buildlink3.mk,v 1.16 2025/01/29 17:30:27 pho Exp $

BUILDLINK_TREE+=	hs-mono-traversable

.if !defined(HS_MONO_TRAVERSABLE_BUILDLINK3_MK)
HS_MONO_TRAVERSABLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-mono-traversable+=	hs-mono-traversable>=1.0.21
BUILDLINK_ABI_DEPENDS.hs-mono-traversable+=	hs-mono-traversable>=1.0.21.0
BUILDLINK_PKGSRCDIR.hs-mono-traversable?=	../../devel/hs-mono-traversable

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-split/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../devel/hs-vector-algorithms/buildlink3.mk"
.endif	# HS_MONO_TRAVERSABLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-mono-traversable
