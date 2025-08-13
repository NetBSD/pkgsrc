# $NetBSD: buildlink3.mk,v 1.15 2025/08/13 11:07:01 pho Exp $

BUILDLINK_TREE+=	hs-tasty-hunit

.if !defined(HS_TASTY_HUNIT_BUILDLINK3_MK)
HS_TASTY_HUNIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tasty-hunit+=	hs-tasty-hunit>=0.10.2
BUILDLINK_ABI_DEPENDS.hs-tasty-hunit+=	hs-tasty-hunit>=0.10.2nb3
BUILDLINK_PKGSRCDIR.hs-tasty-hunit?=	../../devel/hs-tasty-hunit
.endif	# HS_TASTY_HUNIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tasty-hunit
