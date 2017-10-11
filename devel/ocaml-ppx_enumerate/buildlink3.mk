# $NetBSD: buildlink3.mk,v 1.1 2017/10/11 13:57:15 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_enumerate

.if !defined(OCAML_PPX_ENUMERATE_BUILDLINK3_MK)
OCAML_PPX_ENUMERATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_enumerate+=	ocaml-ppx_enumerate>=0.9.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_enumerate?=	../../devel/ocaml-ppx_enumerate
.endif	# OCAML_PPX_ENUMERATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_enumerate
