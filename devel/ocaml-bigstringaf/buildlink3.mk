# $NetBSD: buildlink3.mk,v 1.5 2022/05/30 09:33:00 jaapb Exp $

BUILDLINK_TREE+=	ocaml-bigstringaf

.if !defined(OCAML_BIGSTRINGAF_BUILDLINK3_MK)
OCAML_BIGSTRINGAF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-bigstringaf+=	ocaml-bigstringaf>=0.4.0
BUILDLINK_ABI_DEPENDS.ocaml-bigstringaf+=	ocaml-bigstringaf>=0.9.0nb1
BUILDLINK_PKGSRCDIR.ocaml-bigstringaf?=		../../devel/ocaml-bigstringaf

.endif	# OCAML_BIGSTRINGAF_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-bigstringaf
