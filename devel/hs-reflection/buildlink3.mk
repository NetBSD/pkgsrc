# $NetBSD: buildlink3.mk,v 1.15 2025/03/05 03:39:25 pho Exp $

BUILDLINK_TREE+=	hs-reflection

.if !defined(HS_REFLECTION_BUILDLINK3_MK)
HS_REFLECTION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-reflection+=	hs-reflection>=2.1.9
BUILDLINK_ABI_DEPENDS.hs-reflection+=	hs-reflection>=2.1.9nb2
BUILDLINK_PKGSRCDIR.hs-reflection?=	../../devel/hs-reflection
.endif	# HS_REFLECTION_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-reflection
