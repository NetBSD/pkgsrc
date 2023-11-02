# $NetBSD: buildlink3.mk,v 1.8 2023/11/02 06:36:24 pho Exp $

BUILDLINK_TREE+=	hs-control-monad-free

.if !defined(HS_CONTROL_MONAD_FREE_BUILDLINK3_MK)
HS_CONTROL_MONAD_FREE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-control-monad-free+=	hs-control-monad-free>=0.6.2
BUILDLINK_ABI_DEPENDS.hs-control-monad-free+=	hs-control-monad-free>=0.6.2nb7
BUILDLINK_PKGSRCDIR.hs-control-monad-free?=	../../devel/hs-control-monad-free
.endif	# HS_CONTROL_MONAD_FREE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-control-monad-free
