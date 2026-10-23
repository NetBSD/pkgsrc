# $NetBSD: buildlink3.mk,v 1.1 2026/10/23 22:28:41 alnsn Exp $

BUILDLINK_TREE+=	ocaml-bz2

.if !defined(OCAML_BZ2_BUILDLINK3_MK)
OCAML_BZ2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-bz2+=	ocaml-bz2>=0.7.0
BUILDLINK_ABI_DEPENDS.ocaml-bz2+=	ocaml-bz2>=0.7.0nb2
BUILDLINK_PKGSRCDIR.ocaml-bz2?=		../../archivers/ocaml-bz2

.include "../../archivers/bzip2/buildlink3.mk"
.endif	# OCAML_BZ2_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-bz2
