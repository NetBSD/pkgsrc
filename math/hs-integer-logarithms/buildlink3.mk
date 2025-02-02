# $NetBSD: buildlink3.mk,v 1.13 2025/02/02 13:05:37 pho Exp $

BUILDLINK_TREE+=	hs-integer-logarithms

.if !defined(HS_INTEGER_LOGARITHMS_BUILDLINK3_MK)
HS_INTEGER_LOGARITHMS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-integer-logarithms+=	hs-integer-logarithms>=1.0.4
BUILDLINK_ABI_DEPENDS.hs-integer-logarithms+=	hs-integer-logarithms>=1.0.4nb1
BUILDLINK_PKGSRCDIR.hs-integer-logarithms?=	../../math/hs-integer-logarithms
.endif	# HS_INTEGER_LOGARITHMS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-integer-logarithms
