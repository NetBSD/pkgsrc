# $NetBSD: buildlink3.mk,v 1.1 2017/07/11 11:20:12 jaapb Exp $

BUILDLINK_TREE+=	ocaml-easy-format

.if !defined(OCAML_EASY_FORMAT_BUILDLINK3_MK)
OCAML_EASY_FORMAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-easy-format+=	ocaml-easy-format>=1.2.0
BUILDLINK_PKGSRCDIR.ocaml-easy-format?=	../../textproc/ocaml-easy-format
.endif	# OCAML_EASY_FORMAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-easy-format
