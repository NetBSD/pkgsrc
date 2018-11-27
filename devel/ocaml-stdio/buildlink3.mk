# $NetBSD: buildlink3.mk,v 1.7 2018/11/27 15:25:39 jaapb Exp $

BUILDLINK_TREE+=	ocaml-stdio

.if !defined(OCAML_STDIO_BUILDLINK3_MK)
OCAML_STDIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-stdio+=	ocaml-stdio>=0.9.0
BUILDLINK_ABI_DEPENDS.ocaml-stdio+=	ocaml-stdio>=0.11.0nb3
BUILDLINK_PKGSRCDIR.ocaml-stdio?=	../../devel/ocaml-stdio
.endif	# OCAML_STDIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-stdio
