# $NetBSD: buildlink3.mk,v 1.1 2020/01/19 13:10:49 pho Exp $

BUILDLINK_TREE+=	hs-fingertree

.if !defined(HS_FINGERTREE_BUILDLINK3_MK)
HS_FINGERTREE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-fingertree+=	hs-fingertree>=0.0.1
BUILDLINK_ABI_DEPENDS.hs-fingertree+=	hs-fingertree>=0.0.1.0
BUILDLINK_PKGSRCDIR.hs-fingertree?=	../../devel/hs-fingertree
.endif	# HS_FINGERTREE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-fingertree
