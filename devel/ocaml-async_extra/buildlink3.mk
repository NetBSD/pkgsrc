# $NetBSD: buildlink3.mk,v 1.4 2022/05/05 10:53:17 jaapb Exp $

BUILDLINK_TREE+=	ocaml-async_extra

.if !defined(OCAML_ASYNC_EXTRA_BUILDLINK3_MK)
OCAML_ASYNC_EXTRA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-async_extra+=	ocaml-async_extra>=0.12.0
BUILDLINK_ABI_DEPENDS.ocaml-async_extra+=	ocaml-async_extra>=0.15.0
BUILDLINK_PKGSRCDIR.ocaml-async_extra?=		../../devel/ocaml-async_extra

.endif	# OCAML_ASYNC_EXTRA_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-async_extra
