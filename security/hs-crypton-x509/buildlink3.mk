# $NetBSD: buildlink3.mk,v 1.3 2024/05/09 01:32:33 pho Exp $

BUILDLINK_TREE+=	hs-crypton-x509

.if !defined(HS_CRYPTON_X509_BUILDLINK3_MK)
HS_CRYPTON_X509_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-crypton-x509+=	hs-crypton-x509>=1.7.6
BUILDLINK_ABI_DEPENDS.hs-crypton-x509+=	hs-crypton-x509>=1.7.6nb2
BUILDLINK_PKGSRCDIR.hs-crypton-x509?=	../../security/hs-crypton-x509

.include "../../devel/hs-asn1-encoding/buildlink3.mk"
.include "../../devel/hs-asn1-parse/buildlink3.mk"
.include "../../devel/hs-asn1-types/buildlink3.mk"
.include "../../security/hs-crypton/buildlink3.mk"
.include "../../time/hs-hourglass/buildlink3.mk"
.include "../../devel/hs-memory/buildlink3.mk"
.include "../../security/hs-pem/buildlink3.mk"
.endif	# HS_CRYPTON_X509_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-crypton-x509
