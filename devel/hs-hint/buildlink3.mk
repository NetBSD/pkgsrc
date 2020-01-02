# $NetBSD: buildlink3.mk,v 1.5 2020/01/02 04:58:07 pho Exp $

BUILDLINK_TREE+=	hs-hint

.if !defined(HS_HINT_BUILDLINK3_MK)
HS_HINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hint+=	hs-hint>=0.7.0
BUILDLINK_ABI_DEPENDS.hs-hint+=	hs-hint>=0.7.0
BUILDLINK_PKGSRCDIR.hs-hint?=	../../devel/hs-hint

.include "../../devel/hs-exceptions/buildlink3.mk"
.include "../../devel/hs-ghc-paths/buildlink3.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.endif	# HS_HINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hint
