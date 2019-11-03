# $NetBSD: buildlink3.mk,v 1.7 2019/11/03 10:39:27 rillig Exp $

BUILDLINK_TREE+=	ocamlmod

.if !defined(OCAMLMOD_BUILDLINK3_MK)
OCAMLMOD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocamlmod+=	ocamlmod>=0.0.7nb1
BUILDLINK_ABI_DEPENDS.ocamlmod+=	ocamlmod>=0.0.8nb4
BUILDLINK_PKGSRCDIR.ocamlmod?=		../../devel/ocamlmod
.endif	# OCAMLMOD_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocamlmod
