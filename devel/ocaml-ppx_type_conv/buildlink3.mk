# $NetBSD: buildlink3.mk,v 1.1 2016/03/04 15:44:28 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_type_conv

.if !defined(OCAML_PPX_TYPE_CONV_BUILDLINK3_MK)
OCAML_PPX_TYPE_CONV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_type_conv+=	ocaml-ppx_type_conv>=113.24.00
BUILDLINK_PKGSRCDIR.ocaml-ppx_type_conv?=	../../devel/ocaml-ppx_type_conv

#.include "../../devel/ocaml-ppx_driver/buildlink3.mk"
.include "../../devel/ocaml-ppx_tools/buildlink3.mk"
.endif	# OCAML_PPX_TYPE_CONV_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_type_conv
