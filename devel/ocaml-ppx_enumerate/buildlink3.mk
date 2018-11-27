# $NetBSD: buildlink3.mk,v 1.5 2018/11/27 23:23:23 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_enumerate

.if !defined(OCAML_PPX_ENUMERATE_BUILDLINK3_MK)
OCAML_PPX_ENUMERATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_enumerate+=	ocaml-ppx_enumerate>=0.9.0
BUILDLINK_ABI_DEPENDS.ocaml-ppx_enumerate+=	ocaml-ppx_enumerate>=0.11.1nb3
BUILDLINK_PKGSRCDIR.ocaml-ppx_enumerate?=	../../devel/ocaml-ppx_enumerate
.endif	# OCAML_PPX_ENUMERATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_enumerate
