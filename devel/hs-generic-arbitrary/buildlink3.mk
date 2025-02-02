# $NetBSD: buildlink3.mk,v 1.3 2025/02/02 13:05:06 pho Exp $

BUILDLINK_TREE+=	hs-generic-arbitrary

.if !defined(HS_GENERIC_ARBITRARY_BUILDLINK3_MK)
HS_GENERIC_ARBITRARY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-generic-arbitrary+=	hs-generic-arbitrary>=1.0.1
BUILDLINK_ABI_DEPENDS.hs-generic-arbitrary+=	hs-generic-arbitrary>=1.0.1nb2
BUILDLINK_PKGSRCDIR.hs-generic-arbitrary?=	../../devel/hs-generic-arbitrary

.include "../../devel/hs-QuickCheck/buildlink3.mk"
.endif	# HS_GENERIC_ARBITRARY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-generic-arbitrary
