# $NetBSD: buildlink3.mk,v 1.6 2020/04/08 08:56:37 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_tools

.if !defined(OCAML_PPX_TOOLS_BUILDLINK3_MK)
OCAML_PPX_TOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_tools+=	ocaml-ppx_tools>=6.0
BUILDLINK_ABI_DEPENDS.ocaml-ppx_tools+=	ocaml-ppx_tools>=6.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_tools?=	../../devel/ocaml-ppx_tools
.endif	# OCAML_PPX_TOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_tools
