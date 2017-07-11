# $NetBSD: buildlink3.mk,v 1.2 2017/07/11 14:15:10 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_core

.if !defined(OCAML_PPX_CORE_BUILDLINK3_MK)
OCAML_PPX_CORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_core+=	ocaml-ppx_core>=113.24.00
BUILDLINK_ABI_DEPENDS.ocaml-ppx_core+=	ocaml-ppx_core>=114.01.04nb2
BUILDLINK_PKGSRCDIR.ocaml-ppx_core?=	../../devel/ocaml-ppx_core
.endif	# OCAML_PPX_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_core
