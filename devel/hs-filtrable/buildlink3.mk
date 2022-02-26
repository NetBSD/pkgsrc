# $NetBSD: buildlink3.mk,v 1.2 2022/02/26 03:57:54 pho Exp $

BUILDLINK_TREE+=	hs-filtrable

.if !defined(HS_FILTRABLE_BUILDLINK3_MK)
HS_FILTRABLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-filtrable+=	hs-filtrable>=0.1.6
BUILDLINK_ABI_DEPENDS.hs-filtrable+=	hs-filtrable>=0.1.6.0nb1
BUILDLINK_PKGSRCDIR.hs-filtrable?=	../../devel/hs-filtrable
.endif	# HS_FILTRABLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-filtrable
