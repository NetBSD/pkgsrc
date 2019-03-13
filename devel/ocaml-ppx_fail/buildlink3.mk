# $NetBSD: buildlink3.mk,v 1.1 2019/03/13 11:24:49 jaapb Exp $

BUILDLINK_TREE+=	ocaml-ppx_fail

.if !defined(OCAML_PPX_FAIL_BUILDLINK3_MK)
OCAML_PPX_FAIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ppx_fail+=	ocaml-ppx_fail>=0.12.0
BUILDLINK_PKGSRCDIR.ocaml-ppx_fail?=	../../devel/ocaml-ppx_fail

.endif	# OCAML_PPX_FAIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ppx_fail
