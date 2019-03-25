# $NetBSD: buildlink3.mk,v 1.1 2019/03/25 09:30:27 jaapb Exp $

BUILDLINK_TREE+=	ocaml-eqaf

.if !defined(OCAML_EQAF_BUILDLINK3_MK)
OCAML_EQAF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-eqaf+=	ocaml-eqaf>=0.2
BUILDLINK_PKGSRCDIR.ocaml-eqaf?=	../../devel/ocaml-eqaf

.endif	# OCAML_EQAF_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-eqaf
