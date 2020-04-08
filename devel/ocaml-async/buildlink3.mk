# $NetBSD: buildlink3.mk,v 1.2 2020/04/08 11:55:26 jaapb Exp $

BUILDLINK_TREE+=	ocaml-async

.if !defined(OCAML_ASYNC_BUILDLINK3_MK)
OCAML_ASYNC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-async+=	ocaml-async>=0.12.0
BUILDLINK_ABI_DEPENDS.ocaml-async+=	ocaml-async>=0.13.0
BUILDLINK_PKGSRCDIR.ocaml-async?=	../../devel/ocaml-async

.endif	# OCAML_ASYNC_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-async
