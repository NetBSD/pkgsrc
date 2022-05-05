# $NetBSD: buildlink3.mk,v 1.1 2022/05/05 08:53:02 jaapb Exp $

BUILDLINK_TREE+=	ocaml-expect_test_helpers_core

.if !defined(OCAML_EXPECT_TEST_HELPERS_CORE_BUILDLINK3_MK)
OCAML_EXPECT_TEST_HELPERS_CORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-expect_test_helpers_core+=	ocaml-expect_test_helpers_core>=0.15.0
BUILDLINK_PKGSRCDIR.ocaml-expect_test_helpers_core?=	../../devel/ocaml-expect_test_helpers_core

.endif	# OCAML_EXPECT_TEST_HELPERS_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-expect_test_helpers_core
