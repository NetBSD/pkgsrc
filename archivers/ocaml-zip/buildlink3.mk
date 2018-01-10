# $NetBSD: buildlink3.mk,v 1.5 2018/01/10 16:53:07 jaapb Exp $

BUILDLINK_TREE+=	ocaml-zip

.if !defined(OCAML_ZIP_BUILDLINK3_MK)
OCAML_ZIP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-zip+=	ocaml-zip>=1.05nb6
BUILDLINK_ABI_DEPENDS.ocaml-zip+=	ocaml-zip>=1.07nb2
BUILDLINK_PKGSRCDIR.ocaml-zip?=		../../archivers/ocaml-zip

.include "../../devel/zlib/buildlink3.mk"
.endif	# OCAML_ZIP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-zip
