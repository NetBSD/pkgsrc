# $NetBSD: buildlink3.mk,v 1.6 2026/02/17 13:38:58 wiz Exp $

BUILDLINK_TREE+=	ocaml-dune-configurator

.if !defined(OCAML_DUNE_CONFIGURATOR_BUILDLINK3_MK)
OCAML_DUNE_CONFIGURATOR_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.ocaml-dune-configurator?=	build

BUILDLINK_API_DEPENDS.ocaml-dune-configurator+=	ocaml-dune-configurator>=3.0.0
BUILDLINK_ABI_DEPENDS.ocaml-dune-configurator+=	ocaml-dune-configurator>=3.21.1nb1
BUILDLINK_PKGSRCDIR.ocaml-dune-configurator?=	../../devel/ocaml-dune-configurator

.include "../../devel/ocaml-dune/buildlink3.mk"
.endif	# OCAML_DUNE_CONFIGURATOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-dune-configurator
