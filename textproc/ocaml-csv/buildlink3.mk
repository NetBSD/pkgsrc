# $NetBSD: buildlink3.mk,v 1.2 2016/07/02 10:11:09 jaapb Exp $

BUILDLINK_TREE+=	ocaml-csv

.if !defined(OCAML_CSV_BUILDLINK3_MK)
OCAML_CSV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-csv+=	ocaml-csv>=1.5
BUILDLINK_PKGSRCDIR.ocaml-csv?=	../../textproc/ocaml-csv

.endif	# OCAML_CSV_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-csv
