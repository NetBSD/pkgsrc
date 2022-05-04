# $NetBSD: buildlink3.mk,v 1.2 2022/05/04 15:24:10 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_cold

.if !defined(OCAML_PPX_COLD_BUILDLINK3_MK)
OCAML_PPX_COLD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_cold+=	ocaml-ppx_cold>=0.13.0
BUILDLINK_ABI_DEPENDS.ocaml-ppx_cold+=	ocaml-ppx_cold>=0.15.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_cold?=	../../devel/ocaml-ppx_cold

.endif	# OCAML_PPX_COLD_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_cold
