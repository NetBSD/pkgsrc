# $NetBSD: buildlink3.mk,v 1.3 2021/05/03 19:01:08 pho Exp $

BUILDLINK_TREE+=	hs-profunctors

.if !defined(HS_PROFUNCTORS_BUILDLINK3_MK)
HS_PROFUNCTORS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-profunctors+=	hs-profunctors>=5.6.2
BUILDLINK_ABI_DEPENDS.hs-profunctors+=	hs-profunctors>=5.6.2nb1
BUILDLINK_PKGSRCDIR.hs-profunctors?=	../../math/hs-profunctors

.include "../../devel/hs-base-orphans/buildlink3.mk"
.include "../../math/hs-bifunctors/buildlink3.mk"
.include "../../math/hs-comonad/buildlink3.mk"
.include "../../math/hs-contravariant/buildlink3.mk"
.include "../../math/hs-distributive/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.endif	# HS_PROFUNCTORS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-profunctors
