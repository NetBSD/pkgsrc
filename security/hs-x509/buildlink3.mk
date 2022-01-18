# $NetBSD: buildlink3.mk,v 1.3 2022/01/18 02:48:21 pho Exp $

BUILDLINK_TREE+=	hs-x509

.if !defined(HS_X509_BUILDLINK3_MK)
HS_X509_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-x509+=	hs-x509>=1.7.5
BUILDLINK_ABI_DEPENDS.hs-x509+=	hs-x509>=1.7.5nb2
BUILDLINK_PKGSRCDIR.hs-x509?=	../../security/hs-x509

.include "../../devel/hs-asn1-encoding/buildlink3.mk"
.include "../../devel/hs-asn1-parse/buildlink3.mk"
.include "../../devel/hs-asn1-types/buildlink3.mk"
.include "../../security/hs-cryptonite/buildlink3.mk"
.include "../../time/hs-hourglass/buildlink3.mk"
.include "../../devel/hs-memory/buildlink3.mk"
.include "../../security/hs-pem/buildlink3.mk"
.endif	# HS_X509_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-x509
