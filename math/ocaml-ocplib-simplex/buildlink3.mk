# $NetBSD: buildlink3.mk,v 1.1 2025/06/05 14:42:22 dkazankov Exp $

BUILDLINK_TREE+=	ocaml-ocplib-simplex

.if !defined(OCAML_OCPLIB_SIMPLEX_BUILDLINK3_MK)
OCAML_OCPLIB_SIMPLEX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ocplib-simplex+=	ocaml-ocplib-simplex>=0.5
BUILDLINK_ABI_DEPENDS.ocaml-ocplib-simplex+=	ocaml-ocplib-simplex>=0.5.1
BUILDLINK_PKGSRCDIR.ocaml-ocplib-simplex?=	../../math/ocaml-ocplib-simplex

.endif	# OCAML_OCPLIB_SIMPLEX_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ocplib-simplex
