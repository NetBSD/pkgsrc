# $NetBSD: buildlink3.mk,v 1.5 2022/05/05 09:35:33 jaapb Exp $

BUILDLINK_TREE+=	ocaml-async_unix

.if !defined(OCAML_ASYNC_UNIX_BUILDLINK3_MK)
OCAML_ASYNC_UNIX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-async_unix+=	ocaml-async_unix>=0.12.0
BUILDLINK_ABI_DEPENDS.ocaml-async_unix+=	ocaml-async_unix>=0.15.0
BUILDLINK_PKGSRCDIR.ocaml-async_unix?=		../../devel/ocaml-async_unix

.endif	# OCAML_ASYNC_UNIX_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-async_unix
