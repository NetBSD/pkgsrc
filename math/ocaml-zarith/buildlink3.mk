# $NetBSD: buildlink3.mk,v 1.2 2017/07/11 14:16:23 jaapb Exp $

BUILDLINK_TREE+=	ocaml-zarith

.if !defined(OCAML_ZARITH_BUILDLINK3_MK)
OCAML_ZARITH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-zarith+=	ocaml-zarith>=1.2.1
BUILDLINK_ABI_DEPENDS.ocaml-zarith+=	ocaml-zarith>=1.4.1nb6
BUILDLINK_PKGSRCDIR.ocaml-zarith?=	../../math/ocaml-zarith

.include "../../devel/gmp/buildlink3.mk"

.endif	# OCAML_ZARITH_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-zarith
