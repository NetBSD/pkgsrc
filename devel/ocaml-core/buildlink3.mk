# $NetBSD: buildlink3.mk,v 1.2 2019/07/01 12:38:53 jaapb Exp $

BUILDLINK_TREE+=	ocaml-core

.if !defined(OCAML_CORE_BUILDLINK3_MK)
OCAML_CORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-core+=	ocaml-core>=0.12.0
BUILDLINK_ABI_DEPENDS.ocaml-core+=	ocaml-core>=0.12.3
BUILDLINK_PKGSRCDIR.ocaml-core?=	../../devel/ocaml-core

.endif	# OCAML_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-core
