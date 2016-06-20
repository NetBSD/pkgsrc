# $NetBSD: buildlink3.mk,v 1.3 2016/06/20 15:20:03 jaapb Exp $

BUILDLINK_TREE+=        ocaml-tyxml

.if !defined(OCAML_TYXML_BUILDLINK3_MK)
OCAML_TYXML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-tyxml+=     ocaml-tyxml>=4.0.0nb1
BUILDLINK_PKGSRCDIR.ocaml-tyxml?=       ../../textproc/ocaml-tyxml

.endif  # OCAML_TYXML_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-tyxml
