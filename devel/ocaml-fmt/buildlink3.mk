# $NetBSD: buildlink3.mk,v 1.3 2019/11/03 10:39:22 rillig Exp $

BUILDLINK_TREE+=	ocaml-fmt

.if !defined(OCAML_FMT_BUILDLINK3_MK)
OCAML_FMT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-fmt+=	ocaml-fmt>=0.8.5
BUILDLINK_ABI_DEPENDS.ocaml-fmt+=	ocaml-fmt>=0.8.5nb1
BUILDLINK_PKGSRCDIR.ocaml-fmt?=		../../devel/ocaml-fmt

.endif	# OCAML_FMT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-fmt
