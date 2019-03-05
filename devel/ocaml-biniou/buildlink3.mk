# $NetBSD: buildlink3.mk,v 1.5 2019/03/05 17:37:10 jaapb Exp $

BUILDLINK_TREE+=	ocaml-biniou

.if !defined(OCAML_BINIOU_BUILDLINK3_MK)
OCAML_BINIOU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-biniou+=	ocaml-biniou>=1.0.13
BUILDLINK_ABI_DEPENDS.ocaml-biniou+=	ocaml-biniou>=1.2.0nb5
BUILDLINK_PKGSRCDIR.ocaml-biniou?=	../../devel/ocaml-biniou

.endif	# OCAML_BINIOU_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-biniou
