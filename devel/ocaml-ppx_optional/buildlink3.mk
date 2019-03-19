# $NetBSD: buildlink3.mk,v 1.1 2019/03/19 10:12:39 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_optional

.if !defined(OCAML_PPX_OPTIONAL_BUILDLINK3_MK)
OCAML_PPX_OPTIONAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_optional+=	ocaml-ppx_optional>=0.12.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_optional?=	../../devel/ocaml-ppx_optional

.endif	# OCAML_PPX_OPTIONAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_optional
