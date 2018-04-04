# $NetBSD: buildlink3.mk,v 1.6 2018/04/04 16:20:15 jaapb Exp $

BUILDLINK_TREE+=	ocaml-sexplib

.if !defined(OCAML_SEXPLIB_BUILDLINK3_MK)
OCAML_SEXPLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-sexplib+=	ocaml-sexplib>=0.9.0
BUILDLINK_ABI_DEPENDS.ocaml-sexplib+=	ocaml-sexplib>=0.10.0nb1
BUILDLINK_PKGSRCDIR.ocaml-sexplib?=	../../devel/ocaml-sexplib

.endif	# OCAML_SEXPLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-sexplib
