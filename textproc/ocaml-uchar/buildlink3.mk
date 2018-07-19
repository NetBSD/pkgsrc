# $NetBSD: buildlink3.mk,v 1.3 2018/07/19 15:15:30 jaapb Exp $

BUILDLINK_TREE+=	ocaml-uchar

.if !defined(OCAML_UCHAR_BUILDLINK3_MK)
OCAML_UCHAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-uchar+=	ocaml-uchar>=0.0.1
BUILDLINK_ABI_DEPENDS.ocaml-uchar+=	ocaml-uchar>=0.0.1nb5
BUILDLINK_PKGSRCDIR.ocaml-uchar?=	../../textproc/ocaml-uchar

.endif	# OCAML_UCHAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-uchar
