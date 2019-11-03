# $NetBSD: buildlink3.mk,v 1.2 2019/11/03 10:39:24 rillig Exp $

BUILDLINK_TREE+=	ocaml-ppx_stable

.if !defined(OCAML_PPX_STABLE_BUILDLINK3_MK)
OCAML_PPX_STABLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_stable+=	ocaml-ppx_stable>=0.12.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_stable?=		../../devel/ocaml-ppx_stable

.endif	# OCAML_PPX_STABLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_stable
