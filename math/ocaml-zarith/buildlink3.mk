# $NetBSD: buildlink3.mk,v 1.5 2022/05/24 17:55:23 jaapb Exp $

BUILDLINK_TREE+=	ocaml-zarith

.if !defined(OCAML_ZARITH_BUILDLINK3_MK)
OCAML_ZARITH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-zarith+=	ocaml-zarith>=1.2.1
BUILDLINK_ABI_DEPENDS.ocaml-zarith+=	ocaml-zarith>=1.12
BUILDLINK_PKGSRCDIR.ocaml-zarith?=	../../math/ocaml-zarith

.include "../../devel/gmp/buildlink3.mk"

.endif	# OCAML_ZARITH_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-zarith
