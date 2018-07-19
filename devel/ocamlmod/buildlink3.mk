# $NetBSD: buildlink3.mk,v 1.6 2018/07/19 15:15:26 jaapb Exp $

BUILDLINK_TREE+=	ocamlmod

.if !defined(OCAMLMOD_BUILDLINK3_MK)
OCAMLMOD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocamlmod+=	ocamlmod>=0.0.7nb1
BUILDLINK_ABI_DEPENDS.ocamlmod+=	ocamlmod>=0.0.8nb4
BUILDLINK_PKGSRCDIR.ocamlmod?=	../../devel/ocamlmod
.endif	# OCAMLMOD_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocamlmod
