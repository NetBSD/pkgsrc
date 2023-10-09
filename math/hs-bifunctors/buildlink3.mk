# $NetBSD: buildlink3.mk,v 1.10 2023/10/09 04:54:39 pho Exp $

BUILDLINK_TREE+=	hs-bifunctors

.if !defined(HS_BIFUNCTORS_BUILDLINK3_MK)
HS_BIFUNCTORS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-bifunctors+=	hs-bifunctors>=5.5.14
BUILDLINK_ABI_DEPENDS.hs-bifunctors+=	hs-bifunctors>=5.5.14nb2
BUILDLINK_PKGSRCDIR.hs-bifunctors?=	../../math/hs-bifunctors

.include "../../devel/hs-base-orphans/buildlink3.mk"
.include "../../math/hs-comonad/buildlink3.mk"
.include "../../devel/hs-th-abstraction/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.endif	# HS_BIFUNCTORS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-bifunctors
