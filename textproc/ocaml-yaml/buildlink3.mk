# $NetBSD: buildlink3.mk,v 1.1 2026/10/24 18:08:25 alnsn Exp $

BUILDLINK_TREE+=	ocaml-yaml

.if !defined(OCAML_YAML_BUILDLINK3_MK)
OCAML_YAML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-yaml+=	ocaml-yaml>=3.2.0
BUILDLINK_ABI_DEPENDS.ocaml-yaml+=	ocaml-yaml>=3.2.0
BUILDLINK_PKGSRCDIR.ocaml-yaml?=	../../textproc/ocaml-yaml

.endif	# OCAML_YAML_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-yaml
