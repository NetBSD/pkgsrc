# $NetBSD: buildlink3.mk,v 1.1 2022/10/08 15:01:01 tonio Exp $

BUILDLINK_TREE+=	ocaml-ppx_import

.if !defined(OCAML_PPX_IMPORT_BUILDLINK3_MK)
OCAML_PPX_IMPORT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_import+=	ocaml-ppx_import>=1.10
BUILDLINK_ABI_DEPENDS.ocaml-ppx_import+=	ocaml-ppx_import>=1.10.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_import?=		../../devel/ocaml-ppx_import
.endif	# OCAML_PPX_IMPORT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_import
