# $NetBSD: buildlink3.mk,v 1.1 2017/07/11 11:27:00 jaapb Exp $

BUILDLINK_TREE+=	ocaml-biniou

.if !defined(OCAML_BINIOU_BUILDLINK3_MK)
OCAML_BINIOU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-biniou+=	ocaml-biniou>=1.0.13
BUILDLINK_PKGSRCDIR.ocaml-biniou?=	../../devel/ocaml-biniou

.endif	# OCAML_BINIOU_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-biniou
