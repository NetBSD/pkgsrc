# $NetBSD: buildlink3.mk,v 1.3 2017/07/11 14:19:20 jaapb Exp $

BUILDLINK_TREE+=	ocamlgraph

.if !defined(OCAMLGRAPH_BUILDLINK3_MK)
OCAMLGRAPH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocamlgraph+=	ocamlgraph>=1.8.7
BUILDLINK_ABI_DEPENDS.ocamlgraph+=	ocamlgraph>=1.8.7nb8
BUILDLINK_PKGSRCDIR.ocamlgraph?=	../../devel/ocamlgraph
.endif	# OCAMLGRAPH_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocamlgraph
