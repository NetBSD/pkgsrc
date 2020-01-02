# $NetBSD: buildlink3.mk,v 1.2 2020/01/02 07:16:27 pho Exp $

BUILDLINK_TREE+=	hs-reflection

.if !defined(HS_REFLECTION_BUILDLINK3_MK)
HS_REFLECTION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-reflection+=	hs-reflection>=2.1.5
BUILDLINK_ABI_DEPENDS.hs-reflection+=	hs-reflection>=2.1.5
BUILDLINK_PKGSRCDIR.hs-reflection?=	../../devel/hs-reflection

.include "../../math/hs-semigroups/buildlink3.mk"
.endif	# HS_REFLECTION_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-reflection
