# $NetBSD: buildlink3.mk,v 1.2 2020/01/16 13:37:46 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_variants_conv

.if !defined(OCAML_PPX_VARIANTS_CONV_BUILDLINK3_MK)
OCAML_PPX_VARIANTS_CONV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_variants_conv+=	ocaml-ppx_variants_conv>=0.12.0
BUILDLINK_ABI_DEPENDS.ocaml-ppx_variants_conv+=	ocaml-ppx_variants_conv>=0.13.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_variants_conv?=	../../devel/ocaml-ppx_variants_conv

.endif	# OCAML_PPX_VARIANTS_CONV_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_variants_conv
