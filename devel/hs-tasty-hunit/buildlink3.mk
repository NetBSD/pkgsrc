# $NetBSD: buildlink3.mk,v 1.1 2020/03/30 16:51:43 riastradh Exp $

BUILDLINK_TREE+=	hs-tasty-hunit

.if !defined(HS_TASTY_HUNIT_BUILDLINK3_MK)
HS_TASTY_HUNIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tasty-hunit+=	hs-tasty-hunit>=0.10.0.2
BUILDLINK_ABI_DEPENDS.hs-tasty-hunit+=	hs-tasty-hunit>=0.10.0.2
BUILDLINK_PKGSRCDIR.hs-tasty-hunit?=	../../devel/hs-tasty-hunit
.endif	# HS_TASTY_HUNIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tasty-hunit
