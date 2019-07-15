# $NetBSD: buildlink3.mk,v 1.1 2019/07/15 10:45:28 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppxfind

.if !defined(OCAML_PPXFIND_BUILDLINK3_MK)
OCAML_PPXFIND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppxfind+=	ocaml-ppxfind>=1.3
BUILDLINK_PKGSRCDIR.ocaml-ppxfind?=	../../devel/ocaml-ppxfind

.endif	# OCAML_PPXFIND_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppxfind
