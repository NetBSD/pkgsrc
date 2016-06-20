# $NetBSD: buildlink3.mk,v 1.2 2016/06/20 15:10:30 jaapb Exp $

BUILDLINK_TREE+=	ocaml-sexplib

.if !defined(OCAML_SEXPLIB_BUILDLINK3_MK)
OCAML_SEXPLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-sexplib+=	ocaml-sexplib>=113.33.03
BUILDLINK_PKGSRCDIR.ocaml-sexplib?=	../../devel/ocaml-sexplib

.endif	# OCAML_SEXPLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-sexplib
