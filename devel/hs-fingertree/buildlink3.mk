# $NetBSD: buildlink3.mk,v 1.9 2023/11/02 06:36:29 pho Exp $

BUILDLINK_TREE+=	hs-fingertree

.if !defined(HS_FINGERTREE_BUILDLINK3_MK)
HS_FINGERTREE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-fingertree+=	hs-fingertree>=0.1.5
BUILDLINK_ABI_DEPENDS.hs-fingertree+=	hs-fingertree>=0.1.5.0nb7
BUILDLINK_PKGSRCDIR.hs-fingertree?=	../../devel/hs-fingertree
.endif	# HS_FINGERTREE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-fingertree
