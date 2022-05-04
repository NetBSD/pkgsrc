# $NetBSD: buildlink3.mk,v 1.4 2022/05/04 16:55:50 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_inline_test

.if !defined(OCAML_PPX_INLINE_TEST_BUILDLINK3_MK)
OCAML_PPX_INLINE_TEST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_inline_test+=	ocaml-ppx_inline_test>=0.12.0
BUILDLINK_ABI_DEPENDS.ocaml-ppx_inline_test+=	ocaml-ppx_inline_test>=0.15.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_inline_test?=	../../devel/ocaml-ppx_inline_test

.endif	# OCAML_PPX_INLINE_TEST_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_inline_test
