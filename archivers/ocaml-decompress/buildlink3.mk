# $NetBSD: buildlink3.mk,v 1.3 2022/05/03 19:45:12 jaapb Exp $

BUILDLINK_TREE+=	ocaml-decompress

.if !defined(OCAML_DECOMPRESS_BUILDLINK3_MK)
OCAML_DECOMPRESS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-decompress+=	ocaml-decompress>=1.4.1
BUILDLINK_API_DEPENDS.ocaml-decompress+=	ocaml-decompress>=1.4.3
BUILDLINK_PKGSRCDIR.ocaml-decompress?=		../../archivers/ocaml-decompress

.endif	# OCAML_DECOMPRESS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-decompress
