# $NetBSD: buildlink3.mk,v 1.11 2019/11/04 21:43:39 rillig Exp $

BUILDLINK_TREE+=	ocaml-csv

.if !defined(OCAML_CSV_BUILDLINK3_MK)
OCAML_CSV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-csv+=	ocaml-csv>=2.0
BUILDLINK_ABI_DEPENDS.ocaml-csv+=	ocaml-csv>=2.2nb1
BUILDLINK_PKGSRCDIR.ocaml-csv?=		../../textproc/ocaml-csv

.endif	# OCAML_CSV_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-csv
