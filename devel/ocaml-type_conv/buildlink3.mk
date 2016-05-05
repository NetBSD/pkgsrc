# $NetBSD: buildlink3.mk,v 1.7 2016/05/05 11:45:36 jaapb Exp $

BUILDLINK_TREE+=	ocaml-type_conv

.if !defined(OCAML_TYPE_CONV_BUILDLINK3_MK)
OCAML_TYPE_CONV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-type_conv+=	ocaml-type_conv>=109.60.01
BUILDLINK_ABI_DEPENDS.ocaml-type_conv?=	ocaml-type_conv>=113.00.02nb3
BUILDLINK_PKGSRCDIR.ocaml-type_conv?=	../../devel/ocaml-type_conv

.include "../../lang/ocaml/buildlink3.mk"
.endif	# OCAML_TYPE_CONV_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-type_conv
