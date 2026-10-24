# $NetBSD: buildlink3.mk,v 1.1 2026/10/24 21:13:55 alnsn Exp $

BUILDLINK_TREE+=	ocaml-ppx_deriving_yaml

.if !defined(OCAML_PPX_DERIVING_YAML_BUILDLINK3_MK)
OCAML_PPX_DERIVING_YAML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_deriving_yaml+=	ocaml-ppx_deriving_yaml>=0.4.0
BUILDLINK_ABI_DEPENDS.ocaml-ppx_deriving_yaml+=	ocaml-ppx_deriving_yaml>=0.4.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_deriving_yaml?=	../../devel/ocaml-ppx_deriving_yaml

.endif	# OCAML_PPX_DERIVING_YAML_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_deriving_yaml
