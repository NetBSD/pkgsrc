# $NetBSD: buildlink3.mk,v 1.8 2023/01/26 11:16:50 pho Exp $

BUILDLINK_TREE+=	hs-bifunctors

.if !defined(HS_BIFUNCTORS_BUILDLINK3_MK)
HS_BIFUNCTORS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-bifunctors+=	hs-bifunctors>=5.5.14
BUILDLINK_ABI_DEPENDS.hs-bifunctors+=	hs-bifunctors>=5.5.14
BUILDLINK_PKGSRCDIR.hs-bifunctors?=	../../math/hs-bifunctors

.include "../../devel/hs-base-orphans/buildlink3.mk"
.include "../../math/hs-comonad/buildlink3.mk"
.include "../../devel/hs-th-abstraction/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.endif	# HS_BIFUNCTORS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-bifunctors
