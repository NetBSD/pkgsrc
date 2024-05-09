# $NetBSD: buildlink3.mk,v 1.3 2024/05/09 01:32:31 pho Exp $

BUILDLINK_TREE+=	hs-crypto-api

.if !defined(HS_CRYPTO_API_BUILDLINK3_MK)
HS_CRYPTO_API_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-crypto-api+=	hs-crypto-api>=0.13.3
BUILDLINK_ABI_DEPENDS.hs-crypto-api+=	hs-crypto-api>=0.13.3nb2
BUILDLINK_PKGSRCDIR.hs-crypto-api?=	../../security/hs-crypto-api

.include "../../devel/hs-cereal/buildlink3.mk"
.include "../../security/hs-entropy/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.endif	# HS_CRYPTO_API_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-crypto-api
