# $NetBSD: buildlink3.mk,v 1.15 2026/11/13 14:39:35 pho Exp $

BUILDLINK_TREE+=	hs-monoid-subclasses

.if !defined(HS_MONOID_SUBCLASSES_BUILDLINK3_MK)
HS_MONOID_SUBCLASSES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-monoid-subclasses+=	hs-monoid-subclasses>=1.2.5
BUILDLINK_ABI_DEPENDS.hs-monoid-subclasses+=	hs-monoid-subclasses>=1.2.5.1nb4
BUILDLINK_PKGSRCDIR.hs-monoid-subclasses?=	../../math/hs-monoid-subclasses

.include "../../math/hs-commutative-semigroups/buildlink3.mk"
.include "../../math/hs-primes/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_MONOID_SUBCLASSES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-monoid-subclasses
