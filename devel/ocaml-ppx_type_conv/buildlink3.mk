# $NetBSD: buildlink3.mk,v 1.3 2017/07/21 14:08:22 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_type_conv

.if !defined(OCAML_PPX_TYPE_CONV_BUILDLINK3_MK)
OCAML_PPX_TYPE_CONV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_type_conv+=	ocaml-ppx_type_conv>=0.9.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_type_conv?=	../../devel/ocaml-ppx_type_conv

.endif	# OCAML_PPX_TYPE_CONV_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_type_conv
