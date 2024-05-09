# $NetBSD: buildlink3.mk,v 1.3 2024/05/09 01:32:33 pho Exp $

BUILDLINK_TREE+=	hs-crypton-x509-validation

.if !defined(HS_CRYPTON_X509_VALIDATION_BUILDLINK3_MK)
HS_CRYPTON_X509_VALIDATION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-crypton-x509-validation+=	hs-crypton-x509-validation>=1.6.12
BUILDLINK_ABI_DEPENDS.hs-crypton-x509-validation+=	hs-crypton-x509-validation>=1.6.12nb2
BUILDLINK_PKGSRCDIR.hs-crypton-x509-validation?=	../../security/hs-crypton-x509-validation

.include "../../devel/hs-asn1-encoding/buildlink3.mk"
.include "../../devel/hs-asn1-types/buildlink3.mk"
.include "../../security/hs-crypton/buildlink3.mk"
.include "../../security/hs-crypton-x509/buildlink3.mk"
.include "../../security/hs-crypton-x509-store/buildlink3.mk"
.include "../../devel/hs-data-default-class/buildlink3.mk"
.include "../../time/hs-hourglass/buildlink3.mk"
.include "../../devel/hs-memory/buildlink3.mk"
.include "../../security/hs-pem/buildlink3.mk"
.endif	# HS_CRYPTON_X509_VALIDATION_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-crypton-x509-validation
