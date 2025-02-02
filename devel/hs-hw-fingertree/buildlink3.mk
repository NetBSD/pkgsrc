# $NetBSD: buildlink3.mk,v 1.6 2025/02/02 13:05:11 pho Exp $

BUILDLINK_TREE+=	hs-hw-fingertree

.if !defined(HS_HW_FINGERTREE_BUILDLINK3_MK)
HS_HW_FINGERTREE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hw-fingertree+=	hs-hw-fingertree>=0.1.2
BUILDLINK_ABI_DEPENDS.hs-hw-fingertree+=	hs-hw-fingertree>=0.1.2.1nb5
BUILDLINK_PKGSRCDIR.hs-hw-fingertree?=		../../devel/hs-hw-fingertree

.include "../../devel/hs-hw-prim/buildlink3.mk"
.endif	# HS_HW_FINGERTREE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hw-fingertree
