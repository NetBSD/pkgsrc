# $NetBSD: buildlink3.mk,v 1.1 2019/03/12 18:38:53 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_sexp_message

.if !defined(OCAML_PPX_SEXP_MESSAGE_BUILDLINK3_MK)
OCAML_PPX_SEXP_MESSAGE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_sexp_message+=	ocaml-ppx_sexp_message>=0.12.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_sexp_message?=	../../devel/ocaml-ppx_sexp_message

.endif	# OCAML_PPX_SEXP_MESSAGE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_sexp_message
