# $NetBSD: buildlink3.mk,v 1.1 2019/03/19 10:25:53 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_pipebang

.if !defined(OCAML_PPX_PIPEBANG_BUILDLINK3_MK)
OCAML_PPX_PIPEBANG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_pipebang+=	ocaml-ppx_pipebang>=0.12.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_pipebang?=	../../devel/ocaml-ppx_pipebang

.endif	# OCAML_PPX_PIPEBANG_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_pipebang
