# $NetBSD: buildlink3.mk,v 1.2 2019/11/03 10:39:21 rillig Exp $

BUILDLINK_TREE+=	ocaml-async_unix

.if !defined(OCAML_ASYNC_UNIX_BUILDLINK3_MK)
OCAML_ASYNC_UNIX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-async_unix+=	ocaml-async_unix>=0.12.0
BUILDLINK_PKGSRCDIR.ocaml-async_unix?=		../../devel/ocaml-async_unix

.endif	# OCAML_ASYNC_UNIX_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-async_unix
