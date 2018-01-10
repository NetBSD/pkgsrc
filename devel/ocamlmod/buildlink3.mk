# $NetBSD: buildlink3.mk,v 1.5 2018/01/10 16:19:00 jaapb Exp $

BUILDLINK_TREE+=	ocamlmod

.if !defined(OCAMLMOD_BUILDLINK3_MK)
OCAMLMOD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocamlmod+=	ocamlmod>=0.0.7nb1
BUILDLINK_ABI_DEPENDS.ocamlmod+=	ocamlmod>=0.0.8nb2
BUILDLINK_PKGSRCDIR.ocamlmod?=	../../devel/ocamlmod
.endif	# OCAMLMOD_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocamlmod
