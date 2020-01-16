# $NetBSD: buildlink3.mk,v 1.2 2020/01/16 13:27:56 jaapb Exp $

BUILDLINK_TREE+=	ocaml-splittable_random

.if !defined(OCAML_SPLITTABLE_RANDOM_BUILDLINK3_MK)
OCAML_SPLITTABLE_RANDOM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-splittable_random+=	ocaml-splittable_random>=0.12.0
BUILDLINK_ABI_DEPENDS.ocaml-splittable_random+=	ocaml-splittable_random>=0.13.0
BUILDLINK_PKGSRCDIR.ocaml-splittable_random?=	../../devel/ocaml-splittable_random

.endif	# OCAML_SPLITTABLE_RANDOM_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-splittable_random
