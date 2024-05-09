# $NetBSD: buildlink3.mk,v 1.2 2024/05/09 01:31:55 pho Exp $

BUILDLINK_TREE+=	hs-generic-arbitrary

.if !defined(HS_GENERIC_ARBITRARY_BUILDLINK3_MK)
HS_GENERIC_ARBITRARY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-generic-arbitrary+=	hs-generic-arbitrary>=1.0.1
BUILDLINK_ABI_DEPENDS.hs-generic-arbitrary+=	hs-generic-arbitrary>=1.0.1nb1
BUILDLINK_PKGSRCDIR.hs-generic-arbitrary?=	../../devel/hs-generic-arbitrary

.include "../../devel/hs-QuickCheck/buildlink3.mk"
.endif	# HS_GENERIC_ARBITRARY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-generic-arbitrary
