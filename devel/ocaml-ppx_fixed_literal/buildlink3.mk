# $NetBSD: buildlink3.mk,v 1.1 2022/05/05 06:25:51 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_fixed_literal

.if !defined(OCAML_PPX_FIXED_LITERAL_BUILDLINK3_MK)
OCAML_PPX_FIXED_LITERAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_fixed_literal+=	ocaml-ppx_fixed_literal>=0.15.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_fixed_literal?=	../../devel/ocaml-ppx_fixed_literal

.endif	# OCAML_PPX_FIXED_LITERAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_fixed_literal
