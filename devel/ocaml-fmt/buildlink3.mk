# $NetBSD: buildlink3.mk,v 1.1 2019/03/12 17:41:27 jaapb Exp $

BUILDLINK_TREE+=	ocaml-fmt

.if !defined(OCAML_FMT_BUILDLINK3_MK)
OCAML_FMT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-fmt+=	ocaml-fmt>=0.8.5
BUILDLINK_PKGSRCDIR.ocaml-fmt?=	../../devel/ocaml-fmt

.endif	# OCAML_FMT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-fmt
