# $NetBSD: buildlink3.mk,v 1.2 2019/07/01 12:42:16 jaapb Exp $

BUILDLINK_TREE+=	ocaml-digestif

.if !defined(OCAML_DIGESTIF_BUILDLINK3_MK)
OCAML_DIGESTIF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-digestif+=	ocaml-digestif>=0.7.1
BUILDLINK_ABI_DEPENDS.ocaml-digestif+=	ocaml-digestif>=0.7.2
BUILDLINK_PKGSRCDIR.ocaml-digestif?=	../../devel/ocaml-digestif

.endif	# OCAML_DIGESTIF_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-digestif
