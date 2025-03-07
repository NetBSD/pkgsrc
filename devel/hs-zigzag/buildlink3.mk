# $NetBSD: buildlink3.mk,v 1.1 2025/03/07 17:04:41 pho Exp $

BUILDLINK_TREE+=	hs-zigzag

.if !defined(HS_ZIGZAG_BUILDLINK3_MK)
HS_ZIGZAG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-zigzag+=	hs-zigzag>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-zigzag+=	hs-zigzag>=0.1.0.0
BUILDLINK_PKGSRCDIR.hs-zigzag?=		../../devel/hs-zigzag

.endif	# HS_ZIGZAG_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-zigzag
