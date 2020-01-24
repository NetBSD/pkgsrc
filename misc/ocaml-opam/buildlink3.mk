# $NetBSD: buildlink3.mk,v 1.10 2020/01/24 16:07:38 jaapb Exp $

BUILDLINK_TREE+=	ocaml-opam

.if !defined(OCAML_OPAM_BUILDLINK3_MK)
OCAML_OPAM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-opam+=	ocaml-opam>=2.0.0
BUILDLINK_ABI_DEPENDS.ocaml-opam+=	ocaml-opam>=2.0.6
BUILDLINK_PKGSRCDIR.ocaml-opam?=	../../misc/ocaml-opam

.endif	# OCAML_OPAM_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-opam
