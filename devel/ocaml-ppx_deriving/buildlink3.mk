# $NetBSD: buildlink3.mk,v 1.10 2022/05/05 11:52:00 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_deriving

.if !defined(OCAML_PPX_DERIVING_BUILDLINK3_MK)
OCAML_PPX_DERIVING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_deriving+=	ocaml-ppx_deriving>=5.0
BUILDLINK_ABI_DEPENDS.ocaml-ppx_deriving+=	ocaml-ppx_deriving>=5.2.1
BUILDLINK_PKGSRCDIR.ocaml-ppx_deriving?=	../../devel/ocaml-ppx_deriving
.endif	# OCAML_PPX_DERIVING_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_deriving
