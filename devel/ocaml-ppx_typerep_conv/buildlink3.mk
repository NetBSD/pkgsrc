# $NetBSD: buildlink3.mk,v 1.1 2019/03/19 10:32:11 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_typerep_conv

.if !defined(OCAML_PPX_TYPEREP_CONV_BUILDLINK3_MK)
OCAML_PPX_TYPEREP_CONV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_typerep_conv+=	ocaml-ppx_typerep_conv>=0.12.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_typerep_conv?=	../../devel/ocaml-ppx_typerep_conv

.endif	# OCAML_PPX_TYPEREP_CONV_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_typerep_conv
