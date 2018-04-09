# $NetBSD: buildlink3.mk,v 1.6 2018/04/09 11:25:48 jaapb Exp $

BUILDLINK_TREE+=	ocaml-opam

.if !defined(OCAML_OPAM_BUILDLINK3_MK)
OCAML_OPAM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-opam+=	ocaml-opam>=1.2.2
BUILDLINK_ABI_DEPENDS.ocaml-opam+=	ocaml-opam>=2.0.0_rc
BUILDLINK_PKGSRCDIR.ocaml-opam?=	../../misc/ocaml-opam

.endif	# OCAML_OPAM_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-opam
