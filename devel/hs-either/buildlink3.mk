# $NetBSD: buildlink3.mk,v 1.1 2020/01/03 05:21:34 pho Exp $

BUILDLINK_TREE+=	hs-either

.if !defined(HS_EITHER_BUILDLINK3_MK)
HS_EITHER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-either+=	hs-either>=5.0.1
BUILDLINK_ABI_DEPENDS.hs-either+=	hs-either>=5.0.1.1
BUILDLINK_PKGSRCDIR.hs-either?=	../../devel/hs-either

.include "../../math/hs-bifunctors/buildlink3.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../math/hs-profunctors/buildlink3.mk"
.include "../../math/hs-semigroupoids/buildlink3.mk"
.include "../../math/hs-semigroups/buildlink3.mk"
.endif	# HS_EITHER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-either
