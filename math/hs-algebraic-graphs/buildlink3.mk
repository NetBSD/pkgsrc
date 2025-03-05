# $NetBSD: buildlink3.mk,v 1.9 2025/03/05 03:39:41 pho Exp $

BUILDLINK_TREE+=	hs-algebraic-graphs

.if !defined(HS_ALGEBRAIC_GRAPHS_BUILDLINK3_MK)
HS_ALGEBRAIC_GRAPHS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-algebraic-graphs+=	hs-algebraic-graphs>=0.7
BUILDLINK_ABI_DEPENDS.hs-algebraic-graphs+=	hs-algebraic-graphs>=0.7nb6
BUILDLINK_PKGSRCDIR.hs-algebraic-graphs?=	../../math/hs-algebraic-graphs
.endif	# HS_ALGEBRAIC_GRAPHS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-algebraic-graphs
