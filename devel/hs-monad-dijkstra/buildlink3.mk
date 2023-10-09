# $NetBSD: buildlink3.mk,v 1.4 2023/10/09 04:54:24 pho Exp $

BUILDLINK_TREE+=	hs-monad-dijkstra

.if !defined(HS_MONAD_DIJKSTRA_BUILDLINK3_MK)
HS_MONAD_DIJKSTRA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-monad-dijkstra+=	hs-monad-dijkstra>=0.1.1
BUILDLINK_ABI_DEPENDS.hs-monad-dijkstra+=	hs-monad-dijkstra>=0.1.1.3nb3
BUILDLINK_PKGSRCDIR.hs-monad-dijkstra?=		../../devel/hs-monad-dijkstra

.include "../../math/hs-free/buildlink3.mk"
.include "../../devel/hs-psqueues/buildlink3.mk"
.endif	# HS_MONAD_DIJKSTRA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-monad-dijkstra
