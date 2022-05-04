# $NetBSD: buildlink3.mk,v 1.5 2022/05/04 18:04:15 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_expect

.if !defined(OCAML_PPX_EXPECT_BUILDLINK3_MK)
OCAML_PPX_EXPECT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_expect+=	ocaml-ppx_expect>=0.12.0
BUILDLINK_ABI_DEPENDS.ocaml-ppx_expect+=	ocaml-ppx_expect>=0.15.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_expect?=		../../devel/ocaml-ppx_expect

.endif	# OCAML_PPX_EXPECT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_expect
