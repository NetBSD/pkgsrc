# $NetBSD: buildlink3.mk,v 1.7 2018/01/10 16:48:21 jaapb Exp $

BUILDLINK_TREE+=	ocaml-tyxml

.if !defined(OCAML_TYXML_BUILDLINK3_MK)
OCAML_TYXML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-tyxml+=     ocaml-tyxml>=4.0.1
BUILDLINK_ABI_DEPENDS.ocaml-tyxml+=     ocaml-tyxml>=4.1.0nb2
BUILDLINK_PKGSRCDIR.ocaml-tyxml?=       ../../textproc/ocaml-tyxml

.endif  # OCAML_TYXML_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-tyxml
