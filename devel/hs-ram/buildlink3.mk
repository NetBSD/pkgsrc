# $NetBSD: buildlink3.mk,v 1.1 2026/11/08 17:58:35 pho Exp $

BUILDLINK_TREE+=	hs-ram

.if !defined(HS_RAM_BUILDLINK3_MK)
HS_RAM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ram+=	hs-ram>=0.22.1
BUILDLINK_ABI_DEPENDS.hs-ram+=	hs-ram>=0.22.1
BUILDLINK_PKGSRCDIR.hs-ram?=	../../devel/hs-ram

.endif	# HS_RAM_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ram
