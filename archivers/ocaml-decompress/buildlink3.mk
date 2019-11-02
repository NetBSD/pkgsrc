# $NetBSD: buildlink3.mk,v 1.2 2019/11/02 22:54:27 rillig Exp $

BUILDLINK_TREE+=	ocaml-decompress

.if !defined(OCAML_DECOMPRESS_BUILDLINK3_MK)
OCAML_DECOMPRESS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-decompress+=	ocaml-decompress>=0.8.1
BUILDLINK_PKGSRCDIR.ocaml-decompress?=		../../archivers/ocaml-decompress

.endif	# OCAML_DECOMPRESS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-decompress
