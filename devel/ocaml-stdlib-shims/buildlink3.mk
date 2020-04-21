# $NetBSD: buildlink3.mk,v 1.1 2020/04/21 10:53:10 jaapb Exp $

BUILDLINK_TREE+=	ocaml-stdlib-shims

.if !defined(OCAML_STDLIB_SHIMS_BUILDLINK3_MK)
OCAML_STDLIB_SHIMS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-stdlib-shims+=	ocaml-stdlib-shims>=0.2.0
BUILDLINK_PKGSRCDIR.ocaml-stdlib-shims?=	../../devel/ocaml-stdlib-shims
.endif	# OCAML_STDLIB_SHIMS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-stdlib-shims
