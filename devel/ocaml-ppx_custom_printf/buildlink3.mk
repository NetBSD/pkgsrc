# $NetBSD: buildlink3.mk,v 1.1 2019/03/13 10:40:28 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_custom_printf

.if !defined(OCAML_PPX_CUSTOM_PRINTF_BUILDLINK3_MK)
OCAML_PPX_CUSTOM_PRINTF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_custom_printf+=	ocaml-ppx_custom_printf>=0.12.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_custom_printf?=	../../devel/ocaml-ppx_custom_printf

.endif	# OCAML_PPX_CUSTOM_PRINTF_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_custom_printf
