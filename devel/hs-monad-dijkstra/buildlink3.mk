# $NetBSD: buildlink3.mk,v 1.7 2024/05/02 10:09:00 pho Exp $

BUILDLINK_TREE+=	hs-monad-dijkstra

.if !defined(HS_MONAD_DIJKSTRA_BUILDLINK3_MK)
HS_MONAD_DIJKSTRA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-monad-dijkstra+=	hs-monad-dijkstra>=0.1.1
BUILDLINK_ABI_DEPENDS.hs-monad-dijkstra+=	hs-monad-dijkstra>=0.1.1.5
BUILDLINK_PKGSRCDIR.hs-monad-dijkstra?=		../../devel/hs-monad-dijkstra

.include "../../math/hs-free/buildlink3.mk"
.include "../../devel/hs-psqueues/buildlink3.mk"
.endif	# HS_MONAD_DIJKSTRA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-monad-dijkstra
