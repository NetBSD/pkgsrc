# $NetBSD: buildlink3.mk,v 1.3 2022/05/04 17:24:19 jaapb Exp $

BUILDLINK_TREE+=	ocaml-variantslib

.if !defined(OCAML_VARIANTSLIB_BUILDLINK3_MK)
OCAML_VARIANTSLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-variantslib+=	ocaml-variantslib>=0.12.0
BUILDLINK_ABI_DEPENDS.ocaml-variantslib+=	ocaml-variantslib>=0.15.0
BUILDLINK_PKGSRCDIR.ocaml-variantslib?=		../../devel/ocaml-variantslib

.endif	# OCAML_VARIANTSLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-variantslib
