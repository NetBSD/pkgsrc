# $NetBSD: buildlink3.mk,v 1.5 2024/05/09 01:31:41 pho Exp $

BUILDLINK_TREE+=	hs-string-conversions

.if !defined(HS_STRING_CONVERSIONS_BUILDLINK3_MK)
HS_STRING_CONVERSIONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-string-conversions+=	hs-string-conversions>=0.4.0
BUILDLINK_ABI_DEPENDS.hs-string-conversions+=	hs-string-conversions>=0.4.0.1nb4
BUILDLINK_PKGSRCDIR.hs-string-conversions?=	../../converters/hs-string-conversions

.include "../../devel/hs-utf8-string/buildlink3.mk"
.endif	# HS_STRING_CONVERSIONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-string-conversions
