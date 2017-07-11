# $NetBSD: buildlink3.mk,v 1.2 2017/07/11 11:35:42 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_type_conv

.if !defined(OCAML_PPX_TYPE_CONV_BUILDLINK3_MK)
OCAML_PPX_TYPE_CONV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_type_conv+=	ocaml-ppx_type_conv>=114.01.04nb2
BUILDLINK_PKGSRCDIR.ocaml-ppx_type_conv?=	../../devel/ocaml-ppx_type_conv

#.include "../../devel/ocaml-ppx_driver/buildlink3.mk"
.include "../../devel/ocaml-ppx_tools/buildlink3.mk"
.endif	# OCAML_PPX_TYPE_CONV_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_type_conv
