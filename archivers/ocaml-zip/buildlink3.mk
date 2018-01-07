# $NetBSD: buildlink3.mk,v 1.4 2018/01/07 13:03:53 rillig Exp $

BUILDLINK_TREE+=	ocaml-zip

.if !defined(OCAML_ZIP_BUILDLINK3_MK)
OCAML_ZIP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-zip+=	ocaml-zip>=1.05nb6
BUILDLINK_ABI_DEPENDS.ocaml-zip+=	ocaml-zip>=1.07
BUILDLINK_PKGSRCDIR.ocaml-zip?=		../../archivers/ocaml-zip

.include "../../devel/zlib/buildlink3.mk"
.endif	# OCAML_ZIP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-zip
