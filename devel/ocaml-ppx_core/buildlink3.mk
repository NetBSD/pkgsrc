# $NetBSD: buildlink3.mk,v 1.4 2018/01/10 16:03:53 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_core

.if !defined(OCAML_PPX_CORE_BUILDLINK3_MK)
OCAML_PPX_CORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_core+=	ocaml-ppx_core>=0.9.0
BUILDLINK_ABI_DEPENDS.ocaml-ppx_core+=	ocaml-ppx_core>=0.9.2
BUILDLINK_PKGSRCDIR.ocaml-ppx_core?=	../../devel/ocaml-ppx_core
.endif	# OCAML_PPX_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_core
