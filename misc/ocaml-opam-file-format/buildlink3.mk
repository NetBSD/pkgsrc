# $NetBSD: buildlink3.mk,v 1.5 2022/03/07 10:27:08 jaapb Exp $

BUILDLINK_TREE+=	ocaml-opam-file-format

.if !defined(OCAML_OPAM_FILE_FORMAT_BUILDLINK3_MK)
OCAML_OPAM_FILE_FORMAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-opam-file-format+=	ocaml-opam-file-format>=2.0.0
BUILDLINK_ABI_DEPENDS.ocaml-opam-file-format+=	ocaml-opam-file-format>=2.1.3
BUILDLINK_PKGSRCDIR.ocaml-opam-file-format?=	../../misc/ocaml-opam-file-format
.endif	# OCAML_OPAM_FILE_FORMAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-opam-file-format
