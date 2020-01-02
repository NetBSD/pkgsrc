# $NetBSD: buildlink3.mk,v 1.4 2020/01/02 02:47:31 pho Exp $

BUILDLINK_TREE+=	hs-MonadRandom

.if !defined(HS_MONADRANDOM_BUILDLINK3_MK)
HS_MONADRANDOM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-MonadRandom+=	hs-MonadRandom>=0.5.1
BUILDLINK_ABI_DEPENDS.hs-MonadRandom+=	hs-MonadRandom>=0.5.1.1
BUILDLINK_PKGSRCDIR.hs-MonadRandom?=	../../devel/hs-MonadRandom

.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.include "../../devel/hs-fail/buildlink3.mk"
.endif	# HS_MONADRANDOM_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-MonadRandom
