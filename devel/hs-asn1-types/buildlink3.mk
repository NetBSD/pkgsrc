# $NetBSD: buildlink3.mk,v 1.1 2020/01/16 23:53:58 pho Exp $

BUILDLINK_TREE+=	hs-asn1-types

.if !defined(HS_ASN1_TYPES_BUILDLINK3_MK)
HS_ASN1_TYPES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-asn1-types+=	hs-asn1-types>=0.3.3
BUILDLINK_ABI_DEPENDS.hs-asn1-types+=	hs-asn1-types>=0.3.3
BUILDLINK_PKGSRCDIR.hs-asn1-types?=	../../devel/hs-asn1-types

.include "../../time/hs-hourglass/buildlink3.mk"
.include "../../devel/hs-memory/buildlink3.mk"
.endif	# HS_ASN1_TYPES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-asn1-types
