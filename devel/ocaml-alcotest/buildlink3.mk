# $NetBSD: buildlink3.mk,v 1.1 2026/10/20 21:14:44 alnsn Exp $

BUILDLINK_TREE+=	ocaml-alcotest

.if !defined(OCAML_ALCOTEST_BUILDLINK3_MK)
OCAML_ALCOTEST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-alcotest+=	ocaml-alcotest>=1.9.1
BUILDLINK_ABI_DEPENDS.ocaml-alcotest+=	ocaml-alcotest>=1.9.1
BUILDLINK_PKGSRCDIR.ocaml-alcotest?=	../../devel/ocaml-alcotest
.endif	# OCAML_ALCOTEST_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-alcotest
