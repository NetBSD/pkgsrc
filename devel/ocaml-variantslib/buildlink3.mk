# $NetBSD: buildlink3.mk,v 1.2 2019/11/03 10:39:26 rillig Exp $

BUILDLINK_TREE+=	ocaml-variantslib

.if !defined(OCAML_VARIANTSLIB_BUILDLINK3_MK)
OCAML_VARIANTSLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-variantslib+=	ocaml-variantslib>=0.12.0
BUILDLINK_PKGSRCDIR.ocaml-variantslib?=		../../devel/ocaml-variantslib

.endif	# OCAML_VARIANTSLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-variantslib
