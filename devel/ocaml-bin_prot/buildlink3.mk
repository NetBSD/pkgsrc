# $NetBSD: buildlink3.mk,v 1.2 2020/04/08 09:19:42 jaapb Exp $

BUILDLINK_TREE+=	ocaml-bin_prot

.if !defined(OCAML_BIN_PROT_BUILDLINK3_MK)
OCAML_BIN_PROT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-bin_prot+=	ocaml-bin_prot>=0.12.0
BUILDLINK_ABI_DEPENDS.ocaml-bin_prot+=	ocaml-bin_prot>=0.13.0
BUILDLINK_PKGSRCDIR.ocaml-bin_prot?=	../../devel/ocaml-bin_prot

.endif	# OCAML_BIN_PROT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-bin_prot
