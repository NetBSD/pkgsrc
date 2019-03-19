# $NetBSD: buildlink3.mk,v 1.1 2019/03/19 10:37:30 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_jane

.if !defined(OCAML_PPX_JANE_BUILDLINK3_MK)
OCAML_PPX_JANE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_jane+=	ocaml-ppx_jane>=0.12.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_jane?=	../../devel/ocaml-ppx_jane

.endif	# OCAML_PPX_JANE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_jane
