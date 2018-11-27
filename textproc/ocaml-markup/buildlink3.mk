# $NetBSD: buildlink3.mk,v 1.6 2018/11/27 17:20:09 jaapb Exp $

BUILDLINK_TREE+=	ocaml-markup

.if !defined(OCAML_MARKUP_BUILDLINK3_MK)
OCAML_MARKUP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-markup+=	ocaml-markup>=0.7.2
BUILDLINK_ABI_DEPENDS.ocaml-markup+=	ocaml-markup>=0.8.0
BUILDLINK_PKGSRCDIR.ocaml-markup?=	../../textproc/ocaml-markup

.endif	# OCAML_MARKUP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-markup
