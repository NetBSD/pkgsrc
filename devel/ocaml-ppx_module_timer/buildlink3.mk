# $NetBSD: buildlink3.mk,v 1.2 2020/01/16 14:28:31 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_module_timer

.if !defined(OCAML_PPX_MODULE_TIMER_BUILDLINK3_MK)
OCAML_PPX_MODULE_TIMER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_module_timer+=	ocaml-ppx_module_timer>=0.12.0
BUILDLINK_ABI_DEPENDS.ocaml-ppx_module_timer+=	ocaml-ppx_module_timer>=0.13.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_module_timer?=	../../devel/ocaml-ppx_module_timer

.endif	# OCAML_PPX_MODULE_TIMER_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_module_timer
