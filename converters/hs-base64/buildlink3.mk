# $NetBSD: buildlink3.mk,v 1.9 2025/08/13 11:06:24 pho Exp $

BUILDLINK_TREE+=	hs-base64

.if !defined(HS_BASE64_BUILDLINK3_MK)
HS_BASE64_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-base64+=	hs-base64>=1.0
BUILDLINK_ABI_DEPENDS.hs-base64+=	hs-base64>=1.0nb4
BUILDLINK_PKGSRCDIR.hs-base64?=		../../converters/hs-base64

.include "../../textproc/hs-text-short/buildlink3.mk"
.endif	# HS_BASE64_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-base64
