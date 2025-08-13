# $NetBSD: buildlink3.mk,v 1.2 2025/08/13 11:07:07 pho Exp $

BUILDLINK_TREE+=	hs-zigzag

.if !defined(HS_ZIGZAG_BUILDLINK3_MK)
HS_ZIGZAG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-zigzag+=	hs-zigzag>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-zigzag+=	hs-zigzag>=0.1.0.0nb1
BUILDLINK_PKGSRCDIR.hs-zigzag?=		../../devel/hs-zigzag

.endif	# HS_ZIGZAG_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-zigzag
