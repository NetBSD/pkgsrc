# $NetBSD: buildlink3.mk,v 1.3 2020/01/17 09:33:45 jaapb Exp $

BUILDLINK_TREE+=	ocaml-core

.if !defined(OCAML_CORE_BUILDLINK3_MK)
OCAML_CORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-core+=	ocaml-core>=0.12.0
BUILDLINK_ABI_DEPENDS.ocaml-core+=	ocaml-core>=0.13.0
BUILDLINK_PKGSRCDIR.ocaml-core?=	../../devel/ocaml-core

.endif	# OCAML_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-core
