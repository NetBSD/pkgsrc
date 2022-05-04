# $NetBSD: buildlink3.mk,v 1.4 2022/05/04 17:01:19 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_bench

.if !defined(OCAML_PPX_BENCH_BUILDLINK3_MK)
OCAML_PPX_BENCH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_bench+=	ocaml-ppx_bench>=0.12.0
BUILDLINK_ABI_DEPENDS.ocaml-ppx_bench+=	ocaml-ppx_bench>=0.15.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_bench?=	../../devel/ocaml-ppx_bench

.endif	# OCAML_PPX_BENCH_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_bench
