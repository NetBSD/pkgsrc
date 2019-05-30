# $NetBSD: buildlink3.mk,v 1.2 2019/05/30 09:37:20 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_fields_conv

.if !defined(OCAML_PPX_FIELDS_CONV_BUILDLINK3_MK)
OCAML_PPX_FIELDS_CONV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_fields_conv+=	ocaml-ppx_fields_conv>=0.12.0
BUILDLINK_ABI_DEPENDS.ocaml-ppx_fields_conv+=	ocaml-ppx_fields_conv>=0.12.0nb1
BUILDLINK_PKGSRCDIR.ocaml-ppx_fields_conv?=	../../devel/ocaml-ppx_fields_conv

.include "../../devel/ocaml-fieldslib/buildlink3.mk"
.endif	# OCAML_PPX_FIELDS_CONV_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_fields_conv
