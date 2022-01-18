# $NetBSD: buildlink3.mk,v 1.3 2022/01/18 02:48:03 pho Exp $

BUILDLINK_TREE+=	hs-asn1-parse

.if !defined(HS_ASN1_PARSE_BUILDLINK3_MK)
HS_ASN1_PARSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-asn1-parse+=	hs-asn1-parse>=0.9.5
BUILDLINK_ABI_DEPENDS.hs-asn1-parse+=	hs-asn1-parse>=0.9.5nb2
BUILDLINK_PKGSRCDIR.hs-asn1-parse?=	../../devel/hs-asn1-parse

.include "../../devel/hs-asn1-encoding/buildlink3.mk"
.include "../../devel/hs-asn1-types/buildlink3.mk"
.endif	# HS_ASN1_PARSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-asn1-parse
