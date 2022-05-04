# $NetBSD: buildlink3.mk,v 1.11 2022/05/04 16:43:36 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_optcomp

.if !defined(OCAML_PPX_OPTCOMP_BUILDLINK3_MK)
OCAML_PPX_OPTCOMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_optcomp+=	ocaml-ppx_optcomp>=0.9.0
BUILDLINK_ABI_DEPENDS.ocaml-ppx_optcomp+=	ocaml-ppx_optcomp>=0.15.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_optcomp?=		../../devel/ocaml-ppx_optcomp

.endif	# OCAML_PPX_OPTCOMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_optcomp
