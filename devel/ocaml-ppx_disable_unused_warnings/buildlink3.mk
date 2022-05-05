# $NetBSD: buildlink3.mk,v 1.1 2022/05/05 06:36:25 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_disable_unused_warnings

.if !defined(OCAML_PPX_DISABLE_UNUSED_WARNINGS_BUILDLINK3_MK)
OCAML_PPX_DISABLE_UNUSED_WARNINGS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_disable_unused_warnings+=	ocaml-ppx_disable_unused_warnings>=0.15.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_disable_unused_warnings?=	../../devel/ocaml-ppx_disable_unused_warnings

.endif	# OCAML_PPX_DISABLE_UNUSED_WARNINGS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_disable_unused_warnings
