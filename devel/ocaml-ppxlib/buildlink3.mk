# $NetBSD: buildlink3.mk,v 1.6 2019/05/30 09:29:23 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppxlib

.if !defined(OCAML_PPXLIB_BUILDLINK3_MK)
OCAML_PPXLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppxlib+=	ocaml-ppxlib>=0.3.0
BUILDLINK_ABI_DEPENDS.ocaml-ppxlib+=	ocaml-ppxlib>=0.8.0
BUILDLINK_PKGSRCDIR.ocaml-ppxlib?=	../../devel/ocaml-ppxlib

.endif	# OCAML_PPXLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppxlib
