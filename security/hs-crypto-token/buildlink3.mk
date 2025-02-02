# $NetBSD: buildlink3.mk,v 1.4 2025/02/02 13:05:43 pho Exp $

BUILDLINK_TREE+=	hs-crypto-token

.if !defined(HS_CRYPTO_TOKEN_BUILDLINK3_MK)
HS_CRYPTO_TOKEN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-crypto-token+=	hs-crypto-token>=0.1.2
BUILDLINK_ABI_DEPENDS.hs-crypto-token+=	hs-crypto-token>=0.1.2nb1
BUILDLINK_PKGSRCDIR.hs-crypto-token?=	../../security/hs-crypto-token

.include "../../security/hs-crypton/buildlink3.mk"
.include "../../devel/hs-memory/buildlink3.mk"
.include "../../net/hs-network-byte-order/buildlink3.mk"
.endif	# HS_CRYPTO_TOKEN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-crypto-token
