# $NetBSD: buildlink3.mk,v 1.5 2020/01/11 08:05:40 pho Exp $

BUILDLINK_TREE+=	hs-MonadRandom

.if !defined(HS_MONADRANDOM_BUILDLINK3_MK)
HS_MONADRANDOM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-MonadRandom+=	hs-MonadRandom>=0.5.1
BUILDLINK_ABI_DEPENDS.hs-MonadRandom+=	hs-MonadRandom>=0.5.1.1
BUILDLINK_PKGSRCDIR.hs-MonadRandom?=	../../devel/hs-MonadRandom

.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.endif	# HS_MONADRANDOM_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-MonadRandom
