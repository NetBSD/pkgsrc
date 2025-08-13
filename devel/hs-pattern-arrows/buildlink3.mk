# $NetBSD: buildlink3.mk,v 1.9 2025/08/13 11:06:52 pho Exp $

BUILDLINK_TREE+=	hs-pattern-arrows

.if !defined(HS_PATTERN_ARROWS_BUILDLINK3_MK)
HS_PATTERN_ARROWS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-pattern-arrows+=	hs-pattern-arrows>=0.0.2
BUILDLINK_ABI_DEPENDS.hs-pattern-arrows+=	hs-pattern-arrows>=0.0.2nb8
BUILDLINK_PKGSRCDIR.hs-pattern-arrows?=		../../devel/hs-pattern-arrows
.endif	# HS_PATTERN_ARROWS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-pattern-arrows
