# $NetBSD: buildlink3.mk,v 1.4 2018/11/27 18:57:00 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppxlib

.if !defined(OCAML_PPXLIB_BUILDLINK3_MK)
OCAML_PPXLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppxlib+=	ocaml-ppxlib>=0.3.0
BUILDLINK_ABI_DEPENDS.ocaml-ppxlib+=	ocaml-ppxlib>=0.3.1
BUILDLINK_PKGSRCDIR.ocaml-ppxlib?=	../../devel/ocaml-ppxlib

.endif	# OCAML_PPXLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppxlib
