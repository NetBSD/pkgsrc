# $NetBSD: buildlink3.mk,v 1.5 2022/05/04 13:25:03 jaapb Exp $

BUILDLINK_TREE+=	ocaml-parsexp

.if !defined(OCAML_PARSEXP_BUILDLINK3_MK)
OCAML_PARSEXP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-parsexp+=	ocaml-parsexp>=0.11.0
BUILDLINK_ABI_DEPENDS.ocaml-parsexp+=	ocaml-parsexp>=0.14.2
BUILDLINK_PKGSRCDIR.ocaml-parsexp?=	../../devel/ocaml-parsexp

.endif	# OCAML_PARSEXP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-parsexp
