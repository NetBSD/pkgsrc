# $NetBSD: buildlink3.mk,v 1.3 2022/08/20 08:08:21 wiz Exp $

BUILDLINK_TREE+=	hs-monoid-subclasses

.if !defined(HS_MONOID_SUBCLASSES_BUILDLINK3_MK)
HS_MONOID_SUBCLASSES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-monoid-subclasses+=	hs-monoid-subclasses>=1.1.3
BUILDLINK_ABI_DEPENDS.hs-monoid-subclasses+=	hs-monoid-subclasses>=1.1.3nb2
BUILDLINK_PKGSRCDIR.hs-monoid-subclasses?=	../../math/hs-monoid-subclasses

.include "../../math/hs-primes/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.endif	# HS_MONOID_SUBCLASSES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-monoid-subclasses
