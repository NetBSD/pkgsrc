# $NetBSD: buildlink3.mk,v 1.2 2022/05/04 16:20:15 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_sexp_value

.if !defined(OCAML_PPX_SEXP_VALUE_BUILDLINK3_MK)
OCAML_PPX_SEXP_VALUE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_sexp_value+=	ocaml-ppx_sexp_value>=0.12.0
BUILDLINK_ABI_DEPENDS.ocaml-ppx_sexp_value+=	ocaml-ppx_sexp_value>=0.15.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_sexp_value?=	../../devel/ocaml-ppx_sexp_value

.endif	# OCAML_PPX_SEXP_VALUE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_sexp_value
