# $NetBSD: buildlink3.mk,v 1.6 2024/05/09 01:32:04 pho Exp $

BUILDLINK_TREE+=	hs-monad-loops

.if !defined(HS_MONAD_LOOPS_BUILDLINK3_MK)
HS_MONAD_LOOPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-monad-loops+=	hs-monad-loops>=0.4.3
BUILDLINK_ABI_DEPENDS.hs-monad-loops+=	hs-monad-loops>=0.4.3nb5
BUILDLINK_PKGSRCDIR.hs-monad-loops?=	../../devel/hs-monad-loops
.endif	# HS_MONAD_LOOPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-monad-loops
