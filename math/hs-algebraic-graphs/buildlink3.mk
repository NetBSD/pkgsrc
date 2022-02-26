# $NetBSD: buildlink3.mk,v 1.2 2022/02/26 03:58:16 pho Exp $

BUILDLINK_TREE+=	hs-algebraic-graphs

.if !defined(HS_ALGEBRAIC_GRAPHS_BUILDLINK3_MK)
HS_ALGEBRAIC_GRAPHS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-algebraic-graphs+=	hs-algebraic-graphs>=0.6
BUILDLINK_ABI_DEPENDS.hs-algebraic-graphs+=	hs-algebraic-graphs>=0.6nb1
BUILDLINK_PKGSRCDIR.hs-algebraic-graphs?=	../../math/hs-algebraic-graphs
.endif	# HS_ALGEBRAIC_GRAPHS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-algebraic-graphs
