# $NetBSD: buildlink3.mk,v 1.10 2023/11/02 06:36:18 pho Exp $

BUILDLINK_TREE+=	hs-asn1-types

.if !defined(HS_ASN1_TYPES_BUILDLINK3_MK)
HS_ASN1_TYPES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-asn1-types+=	hs-asn1-types>=0.3.4
BUILDLINK_ABI_DEPENDS.hs-asn1-types+=	hs-asn1-types>=0.3.4nb8
BUILDLINK_PKGSRCDIR.hs-asn1-types?=	../../devel/hs-asn1-types

.include "../../time/hs-hourglass/buildlink3.mk"
.include "../../devel/hs-memory/buildlink3.mk"
.endif	# HS_ASN1_TYPES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-asn1-types
