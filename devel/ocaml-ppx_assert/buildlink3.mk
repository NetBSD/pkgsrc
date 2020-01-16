# $NetBSD: buildlink3.mk,v 1.3 2020/01/16 13:23:05 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_assert

.if !defined(OCAML_PPX_ASSERT_BUILDLINK3_MK)
OCAML_PPX_ASSERT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_assert+=	ocaml-ppx_assert>=0.12.0
BUILDLINK_ABI_DEPENDS.ocaml-ppx_assert+=	ocaml-ppx_assert>=0.13.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_assert?=		../../devel/ocaml-ppx_assert

.endif	# OCAML_PPX_ASSERT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_assert
