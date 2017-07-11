# $NetBSD: buildlink3.mk,v 1.2 2017/07/11 14:19:22 jaapb Exp $

BUILDLINK_TREE+=	ocaml-uchar

.if !defined(OCAML_UCHAR_BUILDLINK3_MK)
OCAML_UCHAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-uchar+=	ocaml-uchar>=0.0.1
BUILDLINK_ABI_DEPENDS.ocaml-uchar+=	ocaml-uchar>=0.0.1nb1
BUILDLINK_PKGSRCDIR.ocaml-uchar?=	../../textproc/ocaml-uchar

.endif	# OCAML_UCHAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-uchar
