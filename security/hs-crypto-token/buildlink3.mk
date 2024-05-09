# $NetBSD: buildlink3.mk,v 1.2 2024/05/09 01:32:32 pho Exp $

BUILDLINK_TREE+=	hs-crypto-token

.if !defined(HS_CRYPTO_TOKEN_BUILDLINK3_MK)
HS_CRYPTO_TOKEN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-crypto-token+=	hs-crypto-token>=0.1.1
BUILDLINK_ABI_DEPENDS.hs-crypto-token+=	hs-crypto-token>=0.1.1nb1
BUILDLINK_PKGSRCDIR.hs-crypto-token?=	../../security/hs-crypto-token

.include "../../security/hs-crypton/buildlink3.mk"
.include "../../devel/hs-memory/buildlink3.mk"
.include "../../net/hs-network-byte-order/buildlink3.mk"
.endif	# HS_CRYPTO_TOKEN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-crypto-token
