# $NetBSD: buildlink3.mk,v 1.8 2022/05/24 18:59:33 jaapb Exp $

BUILDLINK_TREE+=	ocamlmod

.if !defined(OCAMLMOD_BUILDLINK3_MK)
OCAMLMOD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocamlmod+=	ocamlmod>=0.0.7nb1
BUILDLINK_ABI_DEPENDS.ocamlmod+=	ocamlmod>=0.0.8nb7
BUILDLINK_PKGSRCDIR.ocamlmod?=		../../devel/ocamlmod
.endif	# OCAMLMOD_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocamlmod
