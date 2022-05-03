# $NetBSD: buildlink3.mk,v 1.7 2022/05/03 09:27:09 jaapb Exp $

BUILDLINK_TREE+=	ocaml-zip

.if !defined(OCAML_ZIP_BUILDLINK3_MK)
OCAML_ZIP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-zip+=	ocaml-zip>=1.05nb6
BUILDLINK_ABI_DEPENDS.ocaml-zip+=	ocaml-zip>=1.11
BUILDLINK_PKGSRCDIR.ocaml-zip?=		../../archivers/ocaml-zip

.include "../../devel/zlib/buildlink3.mk"
.endif	# OCAML_ZIP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-zip
