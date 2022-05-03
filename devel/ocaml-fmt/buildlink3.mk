# $NetBSD: buildlink3.mk,v 1.4 2022/05/03 19:24:37 jaapb Exp $

BUILDLINK_TREE+=	ocaml-fmt

.if !defined(OCAML_FMT_BUILDLINK3_MK)
OCAML_FMT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-fmt+=	ocaml-fmt>=0.8.5
BUILDLINK_ABI_DEPENDS.ocaml-fmt+=	ocaml-fmt>=0.9.0
BUILDLINK_PKGSRCDIR.ocaml-fmt?=		../../devel/ocaml-fmt

.endif	# OCAML_FMT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-fmt
