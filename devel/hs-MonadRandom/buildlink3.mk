# $NetBSD: buildlink3.mk,v 1.2 2014/11/23 12:52:32 szptvlfn Exp $

BUILDLINK_TREE+=	hs-MonadRandom

.if !defined(HS_MONADRANDOM_BUILDLINK3_MK)
HS_MONADRANDOM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-MonadRandom+=	hs-MonadRandom>=0.3
BUILDLINK_ABI_DEPENDS.hs-MonadRandom+=	hs-MonadRandom>=0.3nb1
BUILDLINK_PKGSRCDIR.hs-MonadRandom?=	../../devel/hs-MonadRandom

.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_MONADRANDOM_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-MonadRandom
