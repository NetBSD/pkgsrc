# $NetBSD: buildlink3.mk,v 1.4 2020/12/11 09:42:41 jaapb Exp $

BUILDLINK_TREE+=	ocaml-async_unix

.if !defined(OCAML_ASYNC_UNIX_BUILDLINK3_MK)
OCAML_ASYNC_UNIX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-async_unix+=	ocaml-async_unix>=0.12.0
BUILDLINK_ABI_DEPENDS.ocaml-async_unix+=	ocaml-async_unix>=0.13.1
BUILDLINK_PKGSRCDIR.ocaml-async_unix?=		../../devel/ocaml-async_unix

.endif	# OCAML_ASYNC_UNIX_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-async_unix
