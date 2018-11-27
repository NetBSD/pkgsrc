# $NetBSD: buildlink3.mk,v 1.5 2018/11/27 23:25:16 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_hash

.if !defined(OCAML_PPX_HASH_BUILDLINK3_MK)
OCAML_PPX_HASH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_hash+=	ocaml-ppx_hash>=0.9.0
BUILDLINK_ABI_DEPENDS.ocaml-ppx_hash+=	ocaml-ppx_hash>=0.11.1nb3
BUILDLINK_PKGSRCDIR.ocaml-ppx_hash?=	../../devel/ocaml-ppx_hash

.endif	# OCAML_PPX_HASH_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_hash
