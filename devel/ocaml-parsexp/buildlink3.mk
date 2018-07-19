# $NetBSD: buildlink3.mk,v 1.2 2018/07/19 15:15:23 jaapb Exp $

BUILDLINK_TREE+=	ocaml-parsexp

.if !defined(OCAML_PARSEXP_BUILDLINK3_MK)
OCAML_PARSEXP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-parsexp+=	ocaml-parsexp>=0.11.0
BUILDLINK_ABI_DEPENDS.ocaml-parsexp+=	ocaml-parsexp>=0.11.0nb1
BUILDLINK_PKGSRCDIR.ocaml-parsexp?=	../../devel/ocaml-parsexp

.endif	# OCAML_PARSEXP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-parsexp
