# $NetBSD: buildlink3.mk,v 1.4 2023/11/05 21:28:13 jaapb Exp $

BUILDLINK_TREE+=	ocaml-dune-configurator

.if !defined(OCAML_DUNE_CONFIGURATOR_BUILDLINK3_MK)
OCAML_DUNE_CONFIGURATOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-dune-configurator+=	ocaml-dune-configurator>=3.0.0
BUILDLINK_ABI_DEPENDS.ocaml-dune-configurator+=	ocaml-dune-configurator>=3.11.1
BUILDLINK_PKGSRCDIR.ocaml-dune-configurator?=	../../devel/ocaml-dune-configurator

.include "../../devel/ocaml-dune/buildlink3.mk"
.endif	# OCAML_DUNE_CONFIGURATOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-dune-configurator
