# $NetBSD: buildlink3.mk,v 1.13 2022/05/19 08:22:33 jaapb Exp $

BUILDLINK_TREE+=	ocaml-csv

.if !defined(OCAML_CSV_BUILDLINK3_MK)
OCAML_CSV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-csv+=	ocaml-csv>=2.0
BUILDLINK_ABI_DEPENDS.ocaml-csv+=	ocaml-csv>=2.4nb1
BUILDLINK_PKGSRCDIR.ocaml-csv?=		../../textproc/ocaml-csv

.endif	# OCAML_CSV_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-csv
