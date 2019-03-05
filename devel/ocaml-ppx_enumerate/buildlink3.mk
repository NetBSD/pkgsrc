# $NetBSD: buildlink3.mk,v 1.6 2019/03/05 18:03:41 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_enumerate

.if !defined(OCAML_PPX_ENUMERATE_BUILDLINK3_MK)
OCAML_PPX_ENUMERATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_enumerate+=	ocaml-ppx_enumerate>=0.9.0
BUILDLINK_ABI_DEPENDS.ocaml-ppx_enumerate+=	ocaml-ppx_enumerate>=0.12.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_enumerate?=	../../devel/ocaml-ppx_enumerate
.endif	# OCAML_PPX_ENUMERATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_enumerate
