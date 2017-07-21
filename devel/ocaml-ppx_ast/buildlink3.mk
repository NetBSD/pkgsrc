# $NetBSD: buildlink3.mk,v 1.1 2017/07/21 10:32:25 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_ast

.if !defined(OCAML_PPX_AST_BUILDLINK3_MK)
OCAML_PPX_AST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_ast+=	ocaml-ppx_ast>=0.9.1
BUILDLINK_PKGSRCDIR.ocaml-ppx_ast?=	../../devel/ocaml-ppx_ast
.endif	# OCAML_PPX_AST_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_ast
