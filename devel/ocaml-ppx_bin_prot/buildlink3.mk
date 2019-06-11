# $NetBSD: buildlink3.mk,v 1.2 2019/06/11 08:44:31 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_bin_prot

.if !defined(OCAML_PPX_BIN_PROT_BUILDLINK3_MK)
OCAML_PPX_BIN_PROT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_bin_prot+=	ocaml-ppx_bin_prot>=0.12.1
BUILDLINK_PKGSRCDIR.ocaml-ppx_bin_prot?=	../../devel/ocaml-ppx_bin_prot

.endif	# OCAML_PPX_BIN_PROT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_bin_prot
