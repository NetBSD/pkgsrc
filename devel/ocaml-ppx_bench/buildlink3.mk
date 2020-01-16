# $NetBSD: buildlink3.mk,v 1.2 2020/01/16 13:26:32 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_bench

.if !defined(OCAML_PPX_BENCH_BUILDLINK3_MK)
OCAML_PPX_BENCH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_bench+=	ocaml-ppx_bench>=0.12.0
BUILDLINK_ABI_DEPENDS.ocaml-ppx_bench+=	ocaml-ppx_bench>=0.13.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_bench?=	../../devel/ocaml-ppx_bench

.endif	# OCAML_PPX_BENCH_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_bench
