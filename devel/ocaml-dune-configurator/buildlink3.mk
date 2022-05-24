# $NetBSD: buildlink3.mk,v 1.3 2022/05/24 18:51:48 jaapb Exp $

BUILDLINK_TREE+=	ocaml-dune-configurator

.if !defined(OCAML_DUNE_CONFIGURATOR_BUILDLINK3_MK)
OCAML_DUNE_CONFIGURATOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-dune-configurator+=	ocaml-dune-configurator>=2.7.1
BUILDLINK_ABI_DEPENDS.ocaml-dune-configurator+=	ocaml-dune-configurator>=2.9.3nb3
BUILDLINK_PKGSRCDIR.ocaml-dune-configurator?=	../../devel/ocaml-dune-configurator

.include "../../devel/ocaml-dune/buildlink3.mk"
.endif	# OCAML_DUNE_CONFIGURATOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-dune-configurator
