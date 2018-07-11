# $NetBSD: buildlink3.mk,v 1.6 2018/07/11 12:04:32 jaapb Exp $

BUILDLINK_TREE+=	ocaml-extlib

.if !defined(OCAML_EXTLIB_BUILDLINK3_MK)
OCAML_EXTLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-extlib+=	ocaml-extlib>=1.7.0
BUILDLINK_ABI_DEPENDS.ocaml-extlib+=	ocaml-extlib>=1.7.5
BUILDLINK_PKGSRCDIR.ocaml-extlib?=	../../devel/ocaml-extlib

.endif	# OCAML_EXTLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-extlib
