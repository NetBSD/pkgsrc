# $NetBSD: buildlink3.mk,v 1.10 2023/11/02 06:36:11 pho Exp $

BUILDLINK_TREE+=	hs-base16-bytestring

.if !defined(HS_BASE16_BYTESTRING_BUILDLINK3_MK)
HS_BASE16_BYTESTRING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-base16-bytestring+=	hs-base16-bytestring>=1.0.1
BUILDLINK_ABI_DEPENDS.hs-base16-bytestring+=	hs-base16-bytestring>=1.0.2.0nb5
BUILDLINK_PKGSRCDIR.hs-base16-bytestring?=	../../converters/hs-base16-bytestring
.endif	# HS_BASE16_BYTESTRING_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-base16-bytestring
