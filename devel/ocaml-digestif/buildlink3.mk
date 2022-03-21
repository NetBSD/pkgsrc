# $NetBSD: buildlink3.mk,v 1.3 2022/03/21 07:59:31 jaapb Exp $

BUILDLINK_TREE+=	ocaml-digestif

.if !defined(OCAML_DIGESTIF_BUILDLINK3_MK)
OCAML_DIGESTIF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-digestif+=	ocaml-digestif>=0.7.1
BUILDLINK_ABI_DEPENDS.ocaml-digestif+=	ocaml-digestif>=1.1.0nb1
BUILDLINK_PKGSRCDIR.ocaml-digestif?=	../../devel/ocaml-digestif

.endif	# OCAML_DIGESTIF_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-digestif
