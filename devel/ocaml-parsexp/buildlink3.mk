# $NetBSD: buildlink3.mk,v 1.3 2018/11/27 15:21:18 jaapb Exp $

BUILDLINK_TREE+=	ocaml-parsexp

.if !defined(OCAML_PARSEXP_BUILDLINK3_MK)
OCAML_PARSEXP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-parsexp+=	ocaml-parsexp>=0.11.0
BUILDLINK_ABI_DEPENDS.ocaml-parsexp+=	ocaml-parsexp>=0.11.0nb3
BUILDLINK_PKGSRCDIR.ocaml-parsexp?=	../../devel/ocaml-parsexp

.endif	# OCAML_PARSEXP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-parsexp
