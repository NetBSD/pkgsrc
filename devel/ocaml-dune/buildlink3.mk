# $NetBSD: buildlink3.mk,v 1.5 2020/01/17 10:29:34 jaapb Exp $

BUILDLINK_TREE+=	ocaml-dune

.if !defined(OCAML_DUNE_BUILDLINK3_MK)
OCAML_DUNE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-dune+=	ocaml-dune>=2.0.0
BUILDLINK_ABI_DEPENDS.ocaml-dune+=	ocaml-dune>=2.1.3nb1
BUILDLINK_PKGSRCDIR.ocaml-dune?=	../../devel/ocaml-dune
.endif	# OCAML_DUNE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-dune
