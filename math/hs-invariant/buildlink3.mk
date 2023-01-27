# $NetBSD: buildlink3.mk,v 1.3 2023/01/27 02:31:23 pho Exp $

BUILDLINK_TREE+=	hs-invariant

.if !defined(HS_INVARIANT_BUILDLINK3_MK)
HS_INVARIANT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-invariant+=	hs-invariant>=0.5.6
BUILDLINK_ABI_DEPENDS.hs-invariant+=	hs-invariant>=0.5.6
BUILDLINK_PKGSRCDIR.hs-invariant?=	../../math/hs-invariant

.include "../../math/hs-bifunctors/buildlink3.mk"
.include "../../math/hs-comonad/buildlink3.mk"
.include "../../math/hs-contravariant/buildlink3.mk"
.include "../../math/hs-profunctors/buildlink3.mk"
.include "../../devel/hs-StateVar/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../devel/hs-th-abstraction/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_INVARIANT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-invariant
