# $NetBSD: buildlink3.mk,v 1.9 2026/11/13 14:39:03 pho Exp $

BUILDLINK_TREE+=	hs-hw-fingertree

.if !defined(HS_HW_FINGERTREE_BUILDLINK3_MK)
HS_HW_FINGERTREE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hw-fingertree+=	hs-hw-fingertree>=0.1.2
BUILDLINK_ABI_DEPENDS.hs-hw-fingertree+=	hs-hw-fingertree>=0.1.2.1nb8
BUILDLINK_PKGSRCDIR.hs-hw-fingertree?=		../../devel/hs-hw-fingertree

.include "../../devel/hs-hw-prim/buildlink3.mk"
.endif	# HS_HW_FINGERTREE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hw-fingertree
