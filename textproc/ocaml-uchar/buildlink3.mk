# $NetBSD: buildlink3.mk,v 1.5 2022/05/24 18:51:55 jaapb Exp $

BUILDLINK_TREE+=	ocaml-uchar

.if !defined(OCAML_UCHAR_BUILDLINK3_MK)
OCAML_UCHAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-uchar+=	ocaml-uchar>=0.0.1
BUILDLINK_ABI_DEPENDS.ocaml-uchar+=	ocaml-uchar>=0.0.2nb2
BUILDLINK_PKGSRCDIR.ocaml-uchar?=	../../textproc/ocaml-uchar

.endif	# OCAML_UCHAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-uchar
