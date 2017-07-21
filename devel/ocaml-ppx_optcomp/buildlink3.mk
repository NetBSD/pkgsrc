# $NetBSD: buildlink3.mk,v 1.3 2017/07/21 13:34:18 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_optcomp

.if !defined(OCAML_PPX_OPTCOMP_BUILDLINK3_MK)
OCAML_PPX_OPTCOMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_optcomp+=	ocaml-ppx_optcomp>=0.9.0
BUILDLINK_ABI_DEPENDS.ocaml-ppx_optcomp+=	ocaml-ppx_optcomp>=0.9.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_optcomp?=	../../devel/ocaml-ppx_optcomp

.include "../../devel/ocaml-ppx_core/buildlink3.mk"
#.include "../../devel/ocaml-ppx_tools/buildlink3.mk"
.endif	# OCAML_PPX_OPTCOMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_optcomp
