# $NetBSD: buildlink3.mk,v 1.10 2026/02/17 13:38:07 wiz Exp $

BUILDLINK_TREE+=	ocaml-dune

.if !defined(OCAML_DUNE_BUILDLINK3_MK)
OCAML_DUNE_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.ocaml-dune?=	build

BUILDLINK_API_DEPENDS.ocaml-dune+=	ocaml-dune>=3.0.0
BUILDLINK_ABI_DEPENDS.ocaml-dune+=	ocaml-dune>=3.11.1
BUILDLINK_PKGSRCDIR.ocaml-dune?=	../../devel/ocaml-dune
.endif	# OCAML_DUNE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-dune
