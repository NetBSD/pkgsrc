# $NetBSD: buildlink3.mk,v 1.11 2023/11/02 06:36:53 pho Exp $

BUILDLINK_TREE+=	hs-reflection

.if !defined(HS_REFLECTION_BUILDLINK3_MK)
HS_REFLECTION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-reflection+=	hs-reflection>=2.1.7
BUILDLINK_ABI_DEPENDS.hs-reflection+=	hs-reflection>=2.1.7nb1
BUILDLINK_PKGSRCDIR.hs-reflection?=	../../devel/hs-reflection
.endif	# HS_REFLECTION_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-reflection
