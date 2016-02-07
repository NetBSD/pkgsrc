# $NetBSD: buildlink3.mk,v 1.1 2016/02/07 21:43:03 markd Exp $

BUILDLINK_TREE+=	ocaml-zarith

.if !defined(OCAML_ZARITH_BUILDLINK3_MK)
OCAML_ZARITH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-zarith+=	ocaml-zarith>=1.2.1
BUILDLINK_PKGSRCDIR.ocaml-zarith?=	../../math/ocaml-zarith

.endif	# OCAML_ZARITH_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-zarith
