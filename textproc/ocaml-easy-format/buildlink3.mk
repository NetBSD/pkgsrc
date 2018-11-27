# $NetBSD: buildlink3.mk,v 1.4 2018/11/27 22:45:00 jaapb Exp $

BUILDLINK_TREE+=	ocaml-easy-format

.if !defined(OCAML_EASY_FORMAT_BUILDLINK3_MK)
OCAML_EASY_FORMAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-easy-format+=	ocaml-easy-format>=1.2.0
BUILDLINK_ABI_DEPENDS.ocaml-easy-format+=	ocaml-easy-format>=1.3.1
BUILDLINK_PKGSRCDIR.ocaml-easy-format?=		../../textproc/ocaml-easy-format
.endif	# OCAML_EASY_FORMAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-easy-format
