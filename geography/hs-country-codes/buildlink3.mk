# $NetBSD: buildlink3.mk,v 1.1 2025/03/07 13:19:24 pho Exp $

BUILDLINK_TREE+=	hs-country-codes

.if !defined(HS_COUNTRY_CODES_BUILDLINK3_MK)
HS_COUNTRY_CODES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-country-codes+=	hs-country-codes>=0.1.4
BUILDLINK_ABI_DEPENDS.hs-country-codes+=	hs-country-codes>=0.1.4
BUILDLINK_PKGSRCDIR.hs-country-codes?=		../../geography/hs-country-codes

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-shakespeare/buildlink3.mk"
.endif	# HS_COUNTRY_CODES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-country-codes
