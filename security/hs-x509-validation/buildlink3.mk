# $NetBSD: buildlink3.mk,v 1.3 2022/01/18 02:48:22 pho Exp $

BUILDLINK_TREE+=	hs-x509-validation

.if !defined(HS_X509_VALIDATION_BUILDLINK3_MK)
HS_X509_VALIDATION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-x509-validation+=	hs-x509-validation>=1.6.11
BUILDLINK_ABI_DEPENDS.hs-x509-validation+=	hs-x509-validation>=1.6.11nb2
BUILDLINK_PKGSRCDIR.hs-x509-validation?=	../../security/hs-x509-validation

.include "../../devel/hs-asn1-encoding/buildlink3.mk"
.include "../../devel/hs-asn1-types/buildlink3.mk"
.include "../../security/hs-cryptonite/buildlink3.mk"
.include "../../devel/hs-data-default-class/buildlink3.mk"
.include "../../time/hs-hourglass/buildlink3.mk"
.include "../../devel/hs-memory/buildlink3.mk"
.include "../../security/hs-pem/buildlink3.mk"
.include "../../security/hs-x509/buildlink3.mk"
.include "../../security/hs-x509-store/buildlink3.mk"
.endif	# HS_X509_VALIDATION_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-x509-validation
