# $NetBSD: buildlink3.mk,v 1.1 2022/05/05 06:17:53 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_string

.if !defined(OCAML_PPX_STRING_BUILDLINK3_MK)
OCAML_PPX_STRING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_string+=	ocaml-ppx_string>=0.15.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_string?=		../../devel/ocaml-ppx_string

.endif	# OCAML_PPX_STRING_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_string
