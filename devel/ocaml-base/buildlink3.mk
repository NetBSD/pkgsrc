# $NetBSD: buildlink3.mk,v 1.12 2022/05/10 08:33:34 jaapb Exp $

BUILDLINK_TREE+=	ocaml-base

.if !defined(OCAML_BASE_BUILDLINK3_MK)
OCAML_BASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-base+=	ocaml-base>=0.9.3
BUILDLINK_ABI_DEPENDS.ocaml-base+=	ocaml-base>=0.15.0
BUILDLINK_PKGSRCDIR.ocaml-base?=	../../devel/ocaml-base
.endif	# OCAML_BASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-base
