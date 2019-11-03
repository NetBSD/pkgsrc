# $NetBSD: buildlink3.mk,v 1.2 2019/11/03 10:39:24 rillig Exp $

BUILDLINK_TREE+=	ocaml-ppx_expect

.if !defined(OCAML_PPX_EXPECT_BUILDLINK3_MK)
OCAML_PPX_EXPECT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_expect+=	ocaml-ppx_expect>=0.12.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_expect?=		../../devel/ocaml-ppx_expect

.endif	# OCAML_PPX_EXPECT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_expect
