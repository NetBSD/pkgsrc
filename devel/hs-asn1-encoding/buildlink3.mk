# $NetBSD: buildlink3.mk,v 1.6 2022/09/07 06:50:45 pho Exp $

BUILDLINK_TREE+=	hs-asn1-encoding

.if !defined(HS_ASN1_ENCODING_BUILDLINK3_MK)
HS_ASN1_ENCODING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-asn1-encoding+=	hs-asn1-encoding>=0.9.6
BUILDLINK_ABI_DEPENDS.hs-asn1-encoding+=	hs-asn1-encoding>=0.9.6nb5
BUILDLINK_PKGSRCDIR.hs-asn1-encoding?=		../../devel/hs-asn1-encoding

.include "../../devel/hs-asn1-types/buildlink3.mk"
.include "../../time/hs-hourglass/buildlink3.mk"
.endif	# HS_ASN1_ENCODING_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-asn1-encoding
