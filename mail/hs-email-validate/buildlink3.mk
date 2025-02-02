# $NetBSD: buildlink3.mk,v 1.6 2025/02/02 13:05:35 pho Exp $

BUILDLINK_TREE+=	hs-email-validate

.if !defined(HS_EMAIL_VALIDATE_BUILDLINK3_MK)
HS_EMAIL_VALIDATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-email-validate+=	hs-email-validate>=2.3.2
BUILDLINK_ABI_DEPENDS.hs-email-validate+=	hs-email-validate>=2.3.2.21nb1
BUILDLINK_PKGSRCDIR.hs-email-validate?=		../../mail/hs-email-validate

.include "../../textproc/hs-attoparsec/buildlink3.mk"
.endif	# HS_EMAIL_VALIDATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-email-validate
