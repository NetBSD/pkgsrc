# $NetBSD: buildlink3.mk,v 1.6 2022/05/02 14:41:56 jaapb Exp $

BUILDLINK_TREE+=	ocaml-sexplib0

.if !defined(OCAML_SEXPLIB0_BUILDLINK3_MK)
OCAML_SEXPLIB0_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-sexplib0+=	ocaml-sexplib0>=0.11.0
BUILDLINK_ABI_DEPENDS.ocaml-sexplib0+=	ocaml-sexplib0>=0.15.0
BUILDLINK_PKGSRCDIR.ocaml-sexplib0?=	../../devel/ocaml-sexplib0

.endif	# OCAML_SEXPLIB0_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-sexplib0
