# $NetBSD: buildlink3.mk,v 1.7 2022/05/24 18:59:33 jaapb Exp $

BUILDLINK_TREE+=	ocamlgraph

.if !defined(OCAMLGRAPH_BUILDLINK3_MK)
OCAMLGRAPH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocamlgraph+=	ocamlgraph>=1.8.7
BUILDLINK_ABI_DEPENDS.ocamlgraph+=	ocamlgraph>=1.8.8nb33
BUILDLINK_PKGSRCDIR.ocamlgraph?=	../../devel/ocamlgraph
.endif	# OCAMLGRAPH_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocamlgraph
