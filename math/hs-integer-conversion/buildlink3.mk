# $NetBSD: buildlink3.mk,v 1.1 2023/10/28 14:33:14 pho Exp $

BUILDLINK_TREE+=	hs-integer-conversion

.if !defined(HS_INTEGER_CONVERSION_BUILDLINK3_MK)
HS_INTEGER_CONVERSION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-integer-conversion+=	hs-integer-conversion>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-integer-conversion+=	hs-integer-conversion>=0.1.0.1
BUILDLINK_PKGSRCDIR.hs-integer-conversion?=	../../math/hs-integer-conversion

.include "../../devel/hs-primitive/buildlink3.mk"
.endif	# HS_INTEGER_CONVERSION_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-integer-conversion
