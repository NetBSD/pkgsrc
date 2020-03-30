# $NetBSD: buildlink3.mk,v 1.1 2020/03/30 16:51:09 riastradh Exp $

BUILDLINK_TREE+=	hs-tasty

.if !defined(HS_TASTY_BUILDLINK3_MK)
HS_TASTY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tasty+=	hs-tasty>=1.2.3
BUILDLINK_ABI_DEPENDS.hs-tasty+=	hs-tasty>=1.2.3
BUILDLINK_PKGSRCDIR.hs-tasty?=		../../devel/hs-tasty
.endif	# HS_TASTY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tasty
