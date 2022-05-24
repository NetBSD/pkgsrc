# $NetBSD: buildlink3.mk,v 1.7 2022/05/24 18:59:23 jaapb Exp $

BUILDLINK_TREE+=	ocaml-biniou

.if !defined(OCAML_BINIOU_BUILDLINK3_MK)
OCAML_BINIOU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-biniou+=	ocaml-biniou>=1.0.13
BUILDLINK_ABI_DEPENDS.ocaml-biniou+=	ocaml-biniou>=1.2.1nb2
BUILDLINK_PKGSRCDIR.ocaml-biniou?=	../../devel/ocaml-biniou

.endif	# OCAML_BINIOU_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-biniou
