# $NetBSD: buildlink3.mk,v 1.2 2018/05/23 08:11:55 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppxlib

.if !defined(OCAML_PPXLIB_BUILDLINK3_MK)
OCAML_PPXLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppxlib+=	ocaml-ppxlib>=0.3.0
BUILDLINK_ABI_DEPENDS.ocaml-ppxlib+=	ocaml-ppxlib>=0.3.0nb1
BUILDLINK_PKGSRCDIR.ocaml-ppxlib?=	../../devel/ocaml-ppxlib

.endif	# OCAML_PPXLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppxlib
