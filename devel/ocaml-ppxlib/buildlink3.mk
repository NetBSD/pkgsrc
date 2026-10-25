# $NetBSD: buildlink3.mk,v 1.10 2026/10/25 01:31:12 alnsn Exp $

BUILDLINK_TREE+=	ocaml-ppxlib

.if !defined(OCAML_PPXLIB_BUILDLINK3_MK)
OCAML_PPXLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppxlib+=	ocaml-ppxlib>=0.3.0
BUILDLINK_ABI_DEPENDS.ocaml-ppxlib+=	ocaml-ppxlib>=0.33.0
BUILDLINK_PKGSRCDIR.ocaml-ppxlib?=	../../devel/ocaml-ppxlib

.endif	# OCAML_PPXLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppxlib
