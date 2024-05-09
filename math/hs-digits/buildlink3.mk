# $NetBSD: buildlink3.mk,v 1.3 2024/05/09 01:32:25 pho Exp $

BUILDLINK_TREE+=	hs-digits

.if !defined(HS_DIGITS_BUILDLINK3_MK)
HS_DIGITS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-digits+=	hs-digits>=0.3.1
BUILDLINK_ABI_DEPENDS.hs-digits+=	hs-digits>=0.3.1nb2
BUILDLINK_PKGSRCDIR.hs-digits?=		../../math/hs-digits

.include "../../devel/hs-QuickCheck/buildlink3.mk"
.endif	# HS_DIGITS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-digits
