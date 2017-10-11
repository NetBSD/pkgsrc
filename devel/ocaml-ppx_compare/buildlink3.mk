# $NetBSD: buildlink3.mk,v 1.1 2017/10/11 13:51:55 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_compare

.if !defined(OCAML_PPX_COMPARE_BUILDLINK3_MK)
OCAML_PPX_COMPARE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_compare+=	ocaml-ppx_compare>=0.9.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_compare?=	../../devel/ocaml-ppx_compare
.endif	# OCAML_PPX_COMPARE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_compare
