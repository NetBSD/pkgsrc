# $NetBSD: buildlink3.mk,v 1.5 2023/01/29 21:14:43 ryoon Exp $

BUILDLINK_TREE+=	ocaml-cairo

.if !defined(OCAML_CAIRO_BUILDLINK3_MK)
OCAML_CAIRO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-cairo+=	ocaml-cairo>=0.6.1
BUILDLINK_ABI_DEPENDS.ocaml-cairo?=	ocaml-cairo>=0.6.4nb3
BUILDLINK_PKGSRCDIR.ocaml-cairo?=	../../graphics/ocaml-cairo

.include "../../graphics/cairo/buildlink3.mk"
.endif	# OCAML_CAIRO_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-cairo
