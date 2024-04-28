# $NetBSD: buildlink3.mk,v 1.6 2024/04/28 11:54:38 pho Exp $

BUILDLINK_TREE+=	hs-commutative-semigroups

.if !defined(HS_COMMUTATIVE_SEMIGROUPS_BUILDLINK3_MK)
HS_COMMUTATIVE_SEMIGROUPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-commutative-semigroups+=	hs-commutative-semigroups>=0.2
BUILDLINK_ABI_DEPENDS.hs-commutative-semigroups+=	hs-commutative-semigroups>=0.2
BUILDLINK_PKGSRCDIR.hs-commutative-semigroups?=		../../math/hs-commutative-semigroups
.endif	# HS_COMMUTATIVE_SEMIGROUPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-commutative-semigroups
