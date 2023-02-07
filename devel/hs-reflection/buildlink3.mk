# $NetBSD: buildlink3.mk,v 1.8 2023/02/07 01:40:47 pho Exp $

BUILDLINK_TREE+=	hs-reflection

.if !defined(HS_REFLECTION_BUILDLINK3_MK)
HS_REFLECTION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-reflection+=	hs-reflection>=2.1.6
BUILDLINK_ABI_DEPENDS.hs-reflection+=	hs-reflection>=2.1.6nb5
BUILDLINK_PKGSRCDIR.hs-reflection?=	../../devel/hs-reflection
.endif	# HS_REFLECTION_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-reflection
