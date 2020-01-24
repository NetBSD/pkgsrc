# $NetBSD: buildlink3.mk,v 1.1 2020/01/24 12:57:08 jaapb Exp $

BUILDLINK_TREE+=	ocaml-cairo

.if !defined(OCAML_CAIRO_BUILDLINK3_MK)
OCAML_CAIRO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-cairo+=	ocaml-cairo>=0.6.1
BUILDLINK_PKGSRCDIR.ocaml-cairo?=	../../graphics/ocaml-cairo

.include "../../graphics/cairo/buildlink3.mk"
.endif	# OCAML_CAIRO_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-cairo
