# $NetBSD: buildlink3.mk,v 1.1 2022/06/13 08:19:27 jaapb Exp $

BUILDLINK_TREE+=	ocaml-mimic

.if !defined(OCAML_MIMIC_BUILDLINK3_MK)
OCAML_MIMIC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-mimic+=	ocaml-mimic>=0.0.5
BUILDLINK_PKGSRCDIR.ocaml-mimic?=	../../net/ocaml-mimic

.endif	# OCAML_MIMIC_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-mimic
