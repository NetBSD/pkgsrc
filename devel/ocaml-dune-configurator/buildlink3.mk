# $NetBSD: buildlink3.mk,v 1.2 2022/03/10 08:49:18 jaapb Exp $

BUILDLINK_TREE+=	ocaml-dune-configurator

.if !defined(OCAML_DUNE_CONFIGURATOR_BUILDLINK3_MK)
OCAML_DUNE_CONFIGURATOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-dune-configurator+=	ocaml-dune-configurator>=2.7.1
BUILDLINK_ABI_DEPENDS.ocaml-dune-configurator+=	ocaml-dune-configurator>=2.9.3nb2
BUILDLINK_PKGSRCDIR.ocaml-dune-configurator?=	../../devel/ocaml-dune-configurator

.include "../../devel/ocaml-dune/buildlink3.mk"
.endif	# OCAML_DUNE_CONFIGURATOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-dune-configurator
