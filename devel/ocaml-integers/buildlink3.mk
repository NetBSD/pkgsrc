# $NetBSD: buildlink3.mk,v 1.1 2026/10/24 15:44:36 alnsn Exp $

BUILDLINK_TREE+=	ocaml-integers

.if !defined(OCAML_INTEGERS_BUILDLINK3_MK)
OCAML_INTEGERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-integers+=	ocaml-integers>=0.7.0
BUILDLINK_ABI_DEPENDS.ocaml-integers+=	ocaml-integers>=0.7.0
BUILDLINK_PKGSRCDIR.ocaml-integers?=	../../devel/ocaml-integers

.endif	# OCAML_INTEGERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-integers
