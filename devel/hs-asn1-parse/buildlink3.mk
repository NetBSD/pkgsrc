# $NetBSD: buildlink3.mk,v 1.12 2025/03/05 03:39:01 pho Exp $

BUILDLINK_TREE+=	hs-asn1-parse

.if !defined(HS_ASN1_PARSE_BUILDLINK3_MK)
HS_ASN1_PARSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-asn1-parse+=	hs-asn1-parse>=0.9.5
BUILDLINK_ABI_DEPENDS.hs-asn1-parse+=	hs-asn1-parse>=0.9.5nb11
BUILDLINK_PKGSRCDIR.hs-asn1-parse?=	../../devel/hs-asn1-parse

.include "../../devel/hs-asn1-encoding/buildlink3.mk"
.include "../../devel/hs-asn1-types/buildlink3.mk"
.endif	# HS_ASN1_PARSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-asn1-parse
