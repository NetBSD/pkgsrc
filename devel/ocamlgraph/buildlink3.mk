# $NetBSD: buildlink3.mk,v 1.6 2018/07/19 15:15:26 jaapb Exp $

BUILDLINK_TREE+=	ocamlgraph

.if !defined(OCAMLGRAPH_BUILDLINK3_MK)
OCAMLGRAPH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocamlgraph+=	ocamlgraph>=1.8.7
BUILDLINK_ABI_DEPENDS.ocamlgraph+=	ocamlgraph>=1.8.8nb10
BUILDLINK_PKGSRCDIR.ocamlgraph?=	../../devel/ocamlgraph
.endif	# OCAMLGRAPH_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocamlgraph
