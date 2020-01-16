# $NetBSD: buildlink3.mk,v 1.2 2020/01/16 13:29:57 jaapb Exp $

BUILDLINK_TREE+=	ocaml-fieldslib

.if !defined(OCAML_FIELDSLIB_BUILDLINK3_MK)
OCAML_FIELDSLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-fieldslib+=	ocaml-fieldslib>=0.12.0
BUILDLINK_ABI_DEPENDS.ocaml-fieldslib+=	ocaml-fieldslib>=0.13.0
BUILDLINK_PKGSRCDIR.ocaml-fieldslib?=	../../devel/ocaml-fieldslib
.endif	# OCAML_FIELDSLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-fieldslib
