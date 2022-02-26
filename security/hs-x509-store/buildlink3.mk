# $NetBSD: buildlink3.mk,v 1.6 2022/02/26 03:58:22 pho Exp $

BUILDLINK_TREE+=	hs-x509-store

.if !defined(HS_X509_STORE_BUILDLINK3_MK)
HS_X509_STORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-x509-store+=	hs-x509-store>=1.6.9
BUILDLINK_ABI_DEPENDS.hs-x509-store+=	hs-x509-store>=1.6.9nb2
BUILDLINK_PKGSRCDIR.hs-x509-store?=	../../security/hs-x509-store

.include "../../devel/hs-asn1-encoding/buildlink3.mk"
.include "../../devel/hs-asn1-types/buildlink3.mk"
.include "../../security/hs-cryptonite/buildlink3.mk"
.include "../../security/hs-pem/buildlink3.mk"
.include "../../security/hs-x509/buildlink3.mk"
.endif	# HS_X509_STORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-x509-store
