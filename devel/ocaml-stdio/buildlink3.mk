# $NetBSD: buildlink3.mk,v 1.1 2017/07/21 10:36:03 jaapb Exp $

BUILDLINK_TREE+=	ocaml-stdio

.if !defined(OCAML_STDIO_BUILDLINK3_MK)
OCAML_STDIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-stdio+=	ocaml-stdio>=0.9.0
BUILDLINK_PKGSRCDIR.ocaml-stdio?=	../../devel/ocaml-stdio
.endif	# OCAML_STDIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-stdio
