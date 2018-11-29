# $NetBSD: buildlink3.mk,v 1.8 2018/11/29 11:56:54 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_optcomp

.if !defined(OCAML_PPX_OPTCOMP_BUILDLINK3_MK)
OCAML_PPX_OPTCOMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_optcomp+=	ocaml-ppx_optcomp>=0.9.0
BUILDLINK_ABI_DEPENDS.ocaml-ppx_optcomp+=	ocaml-ppx_optcomp>=0.11.0nb3
BUILDLINK_PKGSRCDIR.ocaml-ppx_optcomp?=		../../devel/ocaml-ppx_optcomp

.endif	# OCAML_PPX_OPTCOMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_optcomp
