# $NetBSD: buildlink3.mk,v 1.9 2025/08/13 11:06:50 pho Exp $

BUILDLINK_TREE+=	hs-monad-loops

.if !defined(HS_MONAD_LOOPS_BUILDLINK3_MK)
HS_MONAD_LOOPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-monad-loops+=	hs-monad-loops>=0.4.3
BUILDLINK_ABI_DEPENDS.hs-monad-loops+=	hs-monad-loops>=0.4.3nb8
BUILDLINK_PKGSRCDIR.hs-monad-loops?=	../../devel/hs-monad-loops
.endif	# HS_MONAD_LOOPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-monad-loops
