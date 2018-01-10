# $NetBSD: buildlink3.mk,v 1.3 2018/01/10 16:07:46 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_tools

.if !defined(OCAML_PPX_TOOLS_BUILDLINK3_MK)
OCAML_PPX_TOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_tools+=	ocaml-ppx_tools>=0.99.3
BUILDLINK_ABI_DEPENDS.ocaml-ppx_tools+=	ocaml-ppx_tools>=5.1
BUILDLINK_PKGSRCDIR.ocaml-ppx_tools?=	../../devel/ocaml-ppx_tools
.endif	# OCAML_PPX_TOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_tools
