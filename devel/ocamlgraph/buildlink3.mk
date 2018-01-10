# $NetBSD: buildlink3.mk,v 1.5 2018/01/10 16:53:11 jaapb Exp $

BUILDLINK_TREE+=	ocamlgraph

.if !defined(OCAMLGRAPH_BUILDLINK3_MK)
OCAMLGRAPH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocamlgraph+=	ocamlgraph>=1.8.7
BUILDLINK_ABI_DEPENDS.ocamlgraph+=	ocamlgraph>=1.8.8nb3
BUILDLINK_PKGSRCDIR.ocamlgraph?=	../../devel/ocamlgraph
.endif	# OCAMLGRAPH_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocamlgraph
