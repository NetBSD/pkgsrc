# $NetBSD: buildlink3.mk,v 1.8 2018/04/05 12:00:34 jaapb Exp $

BUILDLINK_TREE+=	ocaml-tyxml

.if !defined(OCAML_TYXML_BUILDLINK3_MK)
OCAML_TYXML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-tyxml+=     ocaml-tyxml>=4.0.1
BUILDLINK_ABI_DEPENDS.ocaml-tyxml+=     ocaml-tyxml>=4.2.0
BUILDLINK_PKGSRCDIR.ocaml-tyxml?=       ../../textproc/ocaml-tyxml

.endif  # OCAML_TYXML_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-tyxml
