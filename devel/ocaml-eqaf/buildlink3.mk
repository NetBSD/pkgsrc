# $NetBSD: buildlink3.mk,v 1.2 2022/05/24 18:59:24 jaapb Exp $

BUILDLINK_TREE+=	ocaml-eqaf

.if !defined(OCAML_EQAF_BUILDLINK3_MK)
OCAML_EQAF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-eqaf+=	ocaml-eqaf>=0.2
BUILDLINK_ABI_DEPENDS.ocaml-eqaf+=	ocaml-eqaf>=0.2nb2
BUILDLINK_PKGSRCDIR.ocaml-eqaf?=	../../devel/ocaml-eqaf

.endif	# OCAML_EQAF_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-eqaf
