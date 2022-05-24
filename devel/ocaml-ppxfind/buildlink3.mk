# $NetBSD: buildlink3.mk,v 1.3 2022/05/24 18:59:31 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppxfind

.if !defined(OCAML_PPXFIND_BUILDLINK3_MK)
OCAML_PPXFIND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppxfind+=	ocaml-ppxfind>=1.3
BUILDLINK_ABI_DEPENDS.ocaml-ppxfind+=	ocaml-ppxfind>=1.4nb2
BUILDLINK_PKGSRCDIR.ocaml-ppxfind?=	../../devel/ocaml-ppxfind

.endif	# OCAML_PPXFIND_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppxfind
