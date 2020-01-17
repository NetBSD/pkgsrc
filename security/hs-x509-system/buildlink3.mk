# $NetBSD: buildlink3.mk,v 1.1 2020/01/17 14:40:51 pho Exp $

BUILDLINK_TREE+=	hs-x509-system

.if !defined(HS_X509_SYSTEM_BUILDLINK3_MK)
HS_X509_SYSTEM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-x509-system+=	hs-x509-system>=1.6.6
BUILDLINK_ABI_DEPENDS.hs-x509-system+=	hs-x509-system>=1.6.6
BUILDLINK_PKGSRCDIR.hs-x509-system?=	../../security/hs-x509-system

.include "../../security/hs-pem/buildlink3.mk"
.include "../../security/hs-x509/buildlink3.mk"
.include "../../security/hs-x509-store/buildlink3.mk"
.endif	# HS_X509_SYSTEM_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-x509-system
