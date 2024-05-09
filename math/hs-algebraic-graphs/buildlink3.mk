# $NetBSD: buildlink3.mk,v 1.7 2024/05/09 01:32:24 pho Exp $

BUILDLINK_TREE+=	hs-algebraic-graphs

.if !defined(HS_ALGEBRAIC_GRAPHS_BUILDLINK3_MK)
HS_ALGEBRAIC_GRAPHS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-algebraic-graphs+=	hs-algebraic-graphs>=0.7
BUILDLINK_ABI_DEPENDS.hs-algebraic-graphs+=	hs-algebraic-graphs>=0.7nb4
BUILDLINK_PKGSRCDIR.hs-algebraic-graphs?=	../../math/hs-algebraic-graphs
.endif	# HS_ALGEBRAIC_GRAPHS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-algebraic-graphs
