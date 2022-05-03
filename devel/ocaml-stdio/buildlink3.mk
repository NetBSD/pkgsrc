# $NetBSD: buildlink3.mk,v 1.10 2022/05/03 09:09:08 jaapb Exp $

BUILDLINK_TREE+=	ocaml-stdio

.if !defined(OCAML_STDIO_BUILDLINK3_MK)
OCAML_STDIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-stdio+=	ocaml-stdio>=0.9.0
BUILDLINK_ABI_DEPENDS.ocaml-stdio+=	ocaml-stdio>=0.15.0
BUILDLINK_PKGSRCDIR.ocaml-stdio?=	../../devel/ocaml-stdio
.endif	# OCAML_STDIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-stdio
