# $NetBSD: buildlink3.mk,v 1.4 2023/11/02 06:36:11 pho Exp $

BUILDLINK_TREE+=	hs-base64

.if !defined(HS_BASE64_BUILDLINK3_MK)
HS_BASE64_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-base64+=	hs-base64>=0.4.2
BUILDLINK_ABI_DEPENDS.hs-base64+=	hs-base64>=0.4.2.4nb3
BUILDLINK_PKGSRCDIR.hs-base64?=		../../converters/hs-base64

.include "../../textproc/hs-text-short/buildlink3.mk"
.endif	# HS_BASE64_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-base64
