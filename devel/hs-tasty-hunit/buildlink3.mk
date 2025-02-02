# $NetBSD: buildlink3.mk,v 1.13 2025/02/02 13:05:25 pho Exp $

BUILDLINK_TREE+=	hs-tasty-hunit

.if !defined(HS_TASTY_HUNIT_BUILDLINK3_MK)
HS_TASTY_HUNIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tasty-hunit+=	hs-tasty-hunit>=0.10.2
BUILDLINK_ABI_DEPENDS.hs-tasty-hunit+=	hs-tasty-hunit>=0.10.2nb1
BUILDLINK_PKGSRCDIR.hs-tasty-hunit?=	../../devel/hs-tasty-hunit
.endif	# HS_TASTY_HUNIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tasty-hunit
