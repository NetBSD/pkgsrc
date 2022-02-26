# $NetBSD: buildlink3.mk,v 1.2 2022/02/26 03:58:02 pho Exp $

BUILDLINK_TREE+=	hs-monad-loops

.if !defined(HS_MONAD_LOOPS_BUILDLINK3_MK)
HS_MONAD_LOOPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-monad-loops+=	hs-monad-loops>=0.4.3
BUILDLINK_ABI_DEPENDS.hs-monad-loops+=	hs-monad-loops>=0.4.3nb1
BUILDLINK_PKGSRCDIR.hs-monad-loops?=	../../devel/hs-monad-loops
.endif	# HS_MONAD_LOOPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-monad-loops
