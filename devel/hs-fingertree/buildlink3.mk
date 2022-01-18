# $NetBSD: buildlink3.mk,v 1.3 2022/01/18 02:48:08 pho Exp $

BUILDLINK_TREE+=	hs-fingertree

.if !defined(HS_FINGERTREE_BUILDLINK3_MK)
HS_FINGERTREE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-fingertree+=	hs-fingertree>=0.0.1
BUILDLINK_ABI_DEPENDS.hs-fingertree+=	hs-fingertree>=0.1.4.2nb2
BUILDLINK_PKGSRCDIR.hs-fingertree?=	../../devel/hs-fingertree
.endif	# HS_FINGERTREE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-fingertree
