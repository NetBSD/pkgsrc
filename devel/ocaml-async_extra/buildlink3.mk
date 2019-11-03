# $NetBSD: buildlink3.mk,v 1.2 2019/11/03 10:39:21 rillig Exp $

BUILDLINK_TREE+=	ocaml-async_extra

.if !defined(OCAML_ASYNC_EXTRA_BUILDLINK3_MK)
OCAML_ASYNC_EXTRA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-async_extra+=	ocaml-async_extra>=0.12.0
BUILDLINK_PKGSRCDIR.ocaml-async_extra?=		../../devel/ocaml-async_extra

.endif	# OCAML_ASYNC_EXTRA_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-async_extra
