# $NetBSD: buildlink3.mk,v 1.9 2022/05/02 18:20:27 jaapb Exp $

BUILDLINK_TREE+=	ocaml-markup

.if !defined(OCAML_MARKUP_BUILDLINK3_MK)
OCAML_MARKUP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-markup+=	ocaml-markup>=1.0.0
BUILDLINK_ABI_DEPENDS.ocaml-markup+=	ocaml-markup>=1.0.3
BUILDLINK_PKGSRCDIR.ocaml-markup?=	../../textproc/ocaml-markup

.endif	# OCAML_MARKUP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-markup
