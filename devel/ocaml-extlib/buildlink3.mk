# $NetBSD: buildlink3.mk,v 1.5 2018/06/27 19:32:24 jaapb Exp $

BUILDLINK_TREE+=	ocaml-extlib

.if !defined(OCAML_EXTLIB_BUILDLINK3_MK)
OCAML_EXTLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-extlib+=	ocaml-extlib>=1.7.0
BUILDLINK_ABI_DEPENDS.ocaml-extlib+=	ocaml-extlib>=1.7.4
BUILDLINK_PKGSRCDIR.ocaml-extlib?=	../../devel/ocaml-extlib

.endif	# OCAML_EXTLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-extlib
