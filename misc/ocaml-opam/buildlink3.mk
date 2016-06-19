# $NetBSD: buildlink3.mk,v 1.2 2016/06/19 23:23:02 jaapb Exp $

BUILDLINK_TREE+=	ocaml-opam

.if !defined(OCAML_OPAM_BUILDLINK3_MK)
OCAML_OPAM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-opam+=	ocaml-opam>=1.2.2
BUILDLINK_PKGSRCDIR.ocaml-opam?=	../../misc/ocaml-opam

.endif	# OCAML_OPAM_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-opam
