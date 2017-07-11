# $NetBSD: buildlink3.mk,v 1.3 2017/07/11 10:00:51 jaapb Exp $

BUILDLINK_TREE+=	ocaml-zip

.if !defined(OCAML_ZIP_BUILDLINK3_MK)
OCAML_ZIP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-zip+=	ocaml-zip>=1.05nb6
BUILDLINK_ABI_DEPENDS.ocaml-zip+=	ocaml-zip>=1.07
BUILDLINK_PKGSRCDIR.ocaml-zip?=	../../archivers/ocaml-zip

.include "../../devel/zlib/buildlink3.mk"
.endif	# OCAML_ZIP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-zip
