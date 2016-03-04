# $NetBSD: buildlink3.mk,v 1.1 2016/03/04 15:22:01 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_core

.if !defined(OCAML_PPX_CORE_BUILDLINK3_MK)
OCAML_PPX_CORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_core+=	ocaml-ppx_core>=113.24.00
BUILDLINK_PKGSRCDIR.ocaml-ppx_core?=	../../devel/ocaml-ppx_core
.endif	# OCAML_PPX_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_core
