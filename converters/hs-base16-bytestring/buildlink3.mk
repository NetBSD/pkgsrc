# $NetBSD: buildlink3.mk,v 1.4 2022/01/18 02:48:01 pho Exp $

BUILDLINK_TREE+=	hs-base16-bytestring

.if !defined(HS_BASE16_BYTESTRING_BUILDLINK3_MK)
HS_BASE16_BYTESTRING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-base16-bytestring+=	hs-base16-bytestring>=1.0.1
BUILDLINK_ABI_DEPENDS.hs-base16-bytestring+=	hs-base16-bytestring>=1.0.1.0nb2
BUILDLINK_PKGSRCDIR.hs-base16-bytestring?=	../../converters/hs-base16-bytestring
.endif	# HS_BASE16_BYTESTRING_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-base16-bytestring
