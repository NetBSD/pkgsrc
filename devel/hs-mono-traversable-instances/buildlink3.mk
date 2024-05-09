# $NetBSD: buildlink3.mk,v 1.8 2024/05/09 01:32:05 pho Exp $

BUILDLINK_TREE+=	hs-mono-traversable-instances

.if !defined(HS_MONO_TRAVERSABLE_INSTANCES_BUILDLINK3_MK)
HS_MONO_TRAVERSABLE_INSTANCES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-mono-traversable-instances+=	hs-mono-traversable-instances>=0.1.1
BUILDLINK_ABI_DEPENDS.hs-mono-traversable-instances+=	hs-mono-traversable-instances>=0.1.1.0nb7
BUILDLINK_PKGSRCDIR.hs-mono-traversable-instances?=	../../devel/hs-mono-traversable-instances

.include "../../math/hs-comonad/buildlink3.mk"
.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../devel/hs-dlist-instances/buildlink3.mk"
.include "../../devel/hs-mono-traversable/buildlink3.mk"
.include "../../math/hs-semigroupoids/buildlink3.mk"
.include "../../math/hs-semigroups/buildlink3.mk"
.include "../../devel/hs-vector-instances/buildlink3.mk"
.endif	# HS_MONO_TRAVERSABLE_INSTANCES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-mono-traversable-instances
