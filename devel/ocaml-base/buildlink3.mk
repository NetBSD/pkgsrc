# $NetBSD: buildlink3.mk,v 1.10 2020/04/03 10:53:20 jaapb Exp $

BUILDLINK_TREE+=	ocaml-base

.if !defined(OCAML_BASE_BUILDLINK3_MK)
OCAML_BASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-base+=	ocaml-base>=0.9.3
BUILDLINK_ABI_DEPENDS.ocaml-base+=	ocaml-base>=0.13.1
BUILDLINK_PKGSRCDIR.ocaml-base?=	../../devel/ocaml-base
.endif	# OCAML_BASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-base
