# $NetBSD: buildlink3.mk,v 1.2 2020/01/16 13:03:19 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_sexp_message

.if !defined(OCAML_PPX_SEXP_MESSAGE_BUILDLINK3_MK)
OCAML_PPX_SEXP_MESSAGE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_sexp_message+=	ocaml-ppx_sexp_message>=0.12.0
BUILDLINK_ABI_DEPENDS.ocaml-ppx_sexp_message+=	ocaml-ppx_sexp_message>=0.13.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_sexp_message?=	../../devel/ocaml-ppx_sexp_message

.endif	# OCAML_PPX_SEXP_MESSAGE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_sexp_message
