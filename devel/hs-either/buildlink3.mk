# $NetBSD: buildlink3.mk,v 1.2 2020/01/11 08:32:25 pho Exp $

BUILDLINK_TREE+=	hs-either

.if !defined(HS_EITHER_BUILDLINK3_MK)
HS_EITHER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-either+=	hs-either>=5.0.1
BUILDLINK_ABI_DEPENDS.hs-either+=	hs-either>=5.0.1.1
BUILDLINK_PKGSRCDIR.hs-either?=		../../devel/hs-either

.include "../../math/hs-bifunctors/buildlink3.mk"
.include "../../math/hs-profunctors/buildlink3.mk"
.include "../../math/hs-semigroupoids/buildlink3.mk"
.endif	# HS_EITHER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-either
