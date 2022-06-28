# $NetBSD: buildlink3.mk,v 1.6 2022/06/28 11:34:37 wiz Exp $

BUILDLINK_TREE+=	ocaml-zarith

.if !defined(OCAML_ZARITH_BUILDLINK3_MK)
OCAML_ZARITH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-zarith+=	ocaml-zarith>=1.2.1
BUILDLINK_ABI_DEPENDS.ocaml-zarith+=	ocaml-zarith>=1.12nb1
BUILDLINK_PKGSRCDIR.ocaml-zarith?=	../../math/ocaml-zarith

.include "../../devel/gmp/buildlink3.mk"

.endif	# OCAML_ZARITH_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-zarith
