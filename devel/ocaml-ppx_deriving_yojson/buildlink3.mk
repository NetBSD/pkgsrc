# $NetBSD: buildlink3.mk,v 1.1 2026/10/24 22:32:12 alnsn Exp $

BUILDLINK_TREE+=	ocaml-ppx_deriving_yojson

.if !defined(OCAML_PPX_DERIVING_YOJSON_BUILDLINK3_MK)
OCAML_PPX_DERIVING_YOJSON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_deriving_yojson+=	ocaml-ppx_deriving_yojson>=3.9.1
BUILDLINK_ABI_DEPENDS.ocaml-ppx_deriving_yojson+=	ocaml-ppx_deriving_yojson>=3.9.1
BUILDLINK_PKGSRCDIR.ocaml-ppx_deriving_yojson?=		../../devel/ocaml-ppx_deriving_yojson
.endif	# OCAML_PPX_DERIVING_YOJSON_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_deriving_yojson
