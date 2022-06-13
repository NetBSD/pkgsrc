# $NetBSD: buildlink3.mk,v 1.1 2022/06/13 08:12:02 jaapb Exp $

BUILDLINK_TREE+=	ocaml-mirage-flow

.if !defined(OCAML_MIRAGE_FLOW_BUILDLINK3_MK)
OCAML_MIRAGE_FLOW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-mirage-flow+=	ocaml-mirage-flow>=3.0.0
BUILDLINK_PKGSRCDIR.ocaml-mirage-flow?=		../../devel/ocaml-mirage-flow

.endif	# OCAML_MIRAGE_FLOW_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-mirage-flow
