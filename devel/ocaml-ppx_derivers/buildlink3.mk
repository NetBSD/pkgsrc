# $NetBSD: buildlink3.mk,v 1.6 2019/03/05 16:30:39 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_derivers

.if !defined(OCAML_PPX_DERIVERS_BUILDLINK3_MK)
OCAML_PPX_DERIVERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_derivers+=	ocaml-ppx_derivers>=1.0
BUILDLINK_ABI_DEPENDS.ocaml-ppx_derivers+=	ocaml-ppx_derivers>=1.2nb4
BUILDLINK_PKGSRCDIR.ocaml-ppx_derivers?=	../../devel/ocaml-ppx_derivers
.endif	# OCAML_PPX_DERIVERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_derivers
