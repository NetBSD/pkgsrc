# $NetBSD: buildlink3.mk,v 1.14 2022/10/02 16:20:26 nros Exp $

BUILDLINK_TREE+=	cryptopp

.if !defined(CRYPTOPP_BUILDLINK3_MK)
CRYPTOPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cryptopp+=	cryptopp>=5.6.2
BUILDLINK_ABI_DEPENDS.cryptopp+=	cryptopp>=8.7.0
BUILDLINK_PKGSRCDIR.cryptopp?=		../../security/crypto++
.endif # CRYPTOPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-cryptopp
