# $NetBSD: buildlink3.mk,v 1.1 2019/03/12 18:55:23 jaapb Exp $

BUILDLINK_TREE+=	ocaml-splittable_random

.if !defined(OCAML_SPLITTABLE_RANDOM_BUILDLINK3_MK)
OCAML_SPLITTABLE_RANDOM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-splittable_random+=	ocaml-splittable_random>=0.12.0
BUILDLINK_PKGSRCDIR.ocaml-splittable_random?=	../../devel/ocaml-splittable_random

.endif	# OCAML_SPLITTABLE_RANDOM_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-splittable_random
