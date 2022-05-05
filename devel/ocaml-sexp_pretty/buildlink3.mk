# $NetBSD: buildlink3.mk,v 1.1 2022/05/05 08:46:43 jaapb Exp $

BUILDLINK_TREE+=	ocaml-sexp_pretty

.if !defined(OCAML_SEXP_PRETTY_BUILDLINK3_MK)
OCAML_SEXP_PRETTY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-sexp_pretty+=	ocaml-sexp_pretty>=0.15.0
BUILDLINK_PKGSRCDIR.ocaml-sexp_pretty?=		../../devel/ocaml-sexp_pretty

.endif	# OCAML_SEXP_PRETTY_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-sexp_pretty
