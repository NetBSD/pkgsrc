# $NetBSD: buildlink3.mk,v 1.8 2022/05/24 18:51:48 jaapb Exp $

BUILDLINK_TREE+=	ocaml-dune

.if !defined(OCAML_DUNE_BUILDLINK3_MK)
OCAML_DUNE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-dune+=	ocaml-dune>=2.2.0
BUILDLINK_ABI_DEPENDS.ocaml-dune+=	ocaml-dune>=2.9.3nb1
BUILDLINK_PKGSRCDIR.ocaml-dune?=	../../devel/ocaml-dune
.endif	# OCAML_DUNE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-dune
