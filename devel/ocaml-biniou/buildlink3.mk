# $NetBSD: buildlink3.mk,v 1.2 2018/04/13 12:40:28 jaapb Exp $

BUILDLINK_TREE+=	ocaml-biniou

.if !defined(OCAML_BINIOU_BUILDLINK3_MK)
OCAML_BINIOU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-biniou+=	ocaml-biniou>=1.0.13
BUILDLINK_ABI_DEPENDS.ocaml-biniou+=	ocaml-biniou>=1.2.0nb1
BUILDLINK_PKGSRCDIR.ocaml-biniou?=	../../devel/ocaml-biniou

.endif	# OCAML_BINIOU_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-biniou
