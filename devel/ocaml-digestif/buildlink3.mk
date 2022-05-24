# $NetBSD: buildlink3.mk,v 1.4 2022/05/24 18:59:24 jaapb Exp $

BUILDLINK_TREE+=	ocaml-digestif

.if !defined(OCAML_DIGESTIF_BUILDLINK3_MK)
OCAML_DIGESTIF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-digestif+=	ocaml-digestif>=0.7.1
BUILDLINK_ABI_DEPENDS.ocaml-digestif+=	ocaml-digestif>=1.1.0nb2
BUILDLINK_PKGSRCDIR.ocaml-digestif?=	../../devel/ocaml-digestif

.endif	# OCAML_DIGESTIF_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-digestif
