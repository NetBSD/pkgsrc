# $NetBSD: buildlink3.mk,v 1.11 2019/03/05 17:10:04 jaapb Exp $

BUILDLINK_TREE+=	ocaml-tyxml

.if !defined(OCAML_TYXML_BUILDLINK3_MK)
OCAML_TYXML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-tyxml+=     ocaml-tyxml>=4.0.1
BUILDLINK_ABI_DEPENDS.ocaml-tyxml+=     ocaml-tyxml>=4.3.0nb1
BUILDLINK_PKGSRCDIR.ocaml-tyxml?=       ../../textproc/ocaml-tyxml

.endif  # OCAML_TYXML_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-tyxml
