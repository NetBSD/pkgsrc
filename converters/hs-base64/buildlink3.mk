# $NetBSD: buildlink3.mk,v 1.7 2025/02/02 13:04:51 pho Exp $

BUILDLINK_TREE+=	hs-base64

.if !defined(HS_BASE64_BUILDLINK3_MK)
HS_BASE64_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-base64+=	hs-base64>=1.0
BUILDLINK_ABI_DEPENDS.hs-base64+=	hs-base64>=1.0nb2
BUILDLINK_PKGSRCDIR.hs-base64?=		../../converters/hs-base64

.include "../../textproc/hs-text-short/buildlink3.mk"
.endif	# HS_BASE64_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-base64
