# $NetBSD: buildlink3.mk,v 1.3 2020/12/11 09:10:57 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_stable

.if !defined(OCAML_PPX_STABLE_BUILDLINK3_MK)
OCAML_PPX_STABLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_stable+=	ocaml-ppx_stable>=0.12.0
BUILDLINK_ABI_DEPENDS.ocaml-ppx_stable+=	ocaml-ppx_stable>=0.14.1
BUILDLINK_PKGSRCDIR.ocaml-ppx_stable?=		../../devel/ocaml-ppx_stable

.endif	# OCAML_PPX_STABLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_stable
