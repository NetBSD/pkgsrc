# $NetBSD: buildlink3.mk,v 1.10 2026/11/13 14:39:08 pho Exp $

BUILDLINK_TREE+=	hs-monad-loops

.if !defined(HS_MONAD_LOOPS_BUILDLINK3_MK)
HS_MONAD_LOOPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-monad-loops+=	hs-monad-loops>=0.4.3
BUILDLINK_ABI_DEPENDS.hs-monad-loops+=	hs-monad-loops>=0.4.3nb9
BUILDLINK_PKGSRCDIR.hs-monad-loops?=	../../devel/hs-monad-loops
.endif	# HS_MONAD_LOOPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-monad-loops
