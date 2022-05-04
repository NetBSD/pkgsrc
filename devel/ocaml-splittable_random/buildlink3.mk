# $NetBSD: buildlink3.mk,v 1.3 2022/05/04 17:07:55 jaapb Exp $

BUILDLINK_TREE+=	ocaml-splittable_random

.if !defined(OCAML_SPLITTABLE_RANDOM_BUILDLINK3_MK)
OCAML_SPLITTABLE_RANDOM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-splittable_random+=	ocaml-splittable_random>=0.12.0
BUILDLINK_ABI_DEPENDS.ocaml-splittable_random+=	ocaml-splittable_random>=0.15.0
BUILDLINK_PKGSRCDIR.ocaml-splittable_random?=	../../devel/ocaml-splittable_random

.endif	# OCAML_SPLITTABLE_RANDOM_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-splittable_random
