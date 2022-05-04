# $NetBSD: buildlink3.mk,v 1.3 2022/05/04 18:21:38 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_optional

.if !defined(OCAML_PPX_OPTIONAL_BUILDLINK3_MK)
OCAML_PPX_OPTIONAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_optional+=	ocaml-ppx_optional>=0.12.0
BUILDLINK_ABI_DEPENDS.ocaml-ppx_optional+=	ocaml-ppx_optional>=0.15.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_optional?=	../../devel/ocaml-ppx_optional

.endif	# OCAML_PPX_OPTIONAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_optional
