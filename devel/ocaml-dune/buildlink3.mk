# $NetBSD: buildlink3.mk,v 1.1 2018/11/27 14:27:39 jaapb Exp $

BUILDLINK_TREE+=	ocaml-dune

.if !defined(OCAML_DUNE_BUILDLINK3_MK)
OCAML_DUNE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-dune+=	ocaml-dune>=1.5.1
BUILDLINK_ABI_DEPENDS.ocaml-dune+=	ocaml-dune>=1.5.1
BUILDLINK_PKGSRCDIR.ocaml-dune?=	../../devel/ocaml-dune
.endif	# OCAML_DUNE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-dune
