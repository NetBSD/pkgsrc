# $NetBSD: buildlink3.mk,v 1.1 2022/05/05 09:26:58 jaapb Exp $

BUILDLINK_TREE+=	ocaml-core_unix

.if !defined(OCAML_CORE_UNIX_BUILDLINK3_MK)
OCAML_CORE_UNIX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-core_unix+=	ocaml-core_unix>=0.15.0
BUILDLINK_PKGSRCDIR.ocaml-core_unix?=	../../devel/ocaml-core_unix

.endif	# OCAML_CORE_UNIX_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-core_unix
