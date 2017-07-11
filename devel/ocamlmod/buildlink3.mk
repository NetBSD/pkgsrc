# $NetBSD: buildlink3.mk,v 1.3 2017/07/11 14:11:14 jaapb Exp $

BUILDLINK_TREE+=	ocamlmod

.if !defined(OCAMLMOD_BUILDLINK3_MK)
OCAMLMOD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocamlmod+=	ocamlmod>=0.0.7nb1
BUILDLINK_ABI_DEPENDS.ocamlmod+=	ocamlmod>=0.0.8
BUILDLINK_PKGSRCDIR.ocamlmod?=	../../devel/ocamlmod
.endif	# OCAMLMOD_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocamlmod
