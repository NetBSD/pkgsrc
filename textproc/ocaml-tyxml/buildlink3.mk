# $NetBSD: buildlink3.mk,v 1.14 2022/05/02 18:22:27 jaapb Exp $

BUILDLINK_TREE+=	ocaml-tyxml

.if !defined(OCAML_TYXML_BUILDLINK3_MK)
OCAML_TYXML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-tyxml+=	ocaml-tyxml>=4.0.1
BUILDLINK_ABI_DEPENDS.ocaml-tyxml+=	ocaml-tyxml>=4.5.0
BUILDLINK_PKGSRCDIR.ocaml-tyxml?=	../../textproc/ocaml-tyxml

.endif  # OCAML_TYXML_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-tyxml
