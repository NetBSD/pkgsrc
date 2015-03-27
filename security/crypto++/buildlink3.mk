# $NetBSD: buildlink3.mk,v 1.12 2015/03/27 14:14:26 rodent Exp $

BUILDLINK_TREE+=	cryptopp

.if !defined(CRYPTOPP_BUILDLINK3_MK)
CRYPTOPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cryptopp+=	cryptopp>=5.6.2
BUILDLINK_ABI_DEPENDS.cryptopp+=	cryptopp>=5.6.2
BUILDLINK_PKGSRCDIR.cryptopp?=	../../security/crypto++
.endif # CRYPTOPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-cryptopp
