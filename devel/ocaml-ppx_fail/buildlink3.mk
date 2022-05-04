# $NetBSD: buildlink3.mk,v 1.2 2022/05/04 18:16:40 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_fail

.if !defined(OCAML_PPX_FAIL_BUILDLINK3_MK)
OCAML_PPX_FAIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_fail+=	ocaml-ppx_fail>=0.12.0
BUILDLINK_ABI_DEPENDS.ocaml-ppx_fail+=	ocaml-ppx_fail>=0.14.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_fail?=	../../devel/ocaml-ppx_fail

.endif	# OCAML_PPX_FAIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_fail
