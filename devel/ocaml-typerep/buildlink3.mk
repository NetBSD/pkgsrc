# $NetBSD: buildlink3.mk,v 1.2 2020/01/16 14:24:08 jaapb Exp $

BUILDLINK_TREE+=	ocaml-typerep

.if !defined(OCAML_TYPEREP_BUILDLINK3_MK)
OCAML_TYPEREP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-typerep+=	ocaml-typerep>=0.12.0
BUILDLINK_ABI_DEPENDS.ocaml-typerep+=	ocaml-typerep>=0.13.0
BUILDLINK_PKGSRCDIR.ocaml-typerep?=	../../devel/ocaml-typerep

.endif	# OCAML_TYPEREP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-typerep
