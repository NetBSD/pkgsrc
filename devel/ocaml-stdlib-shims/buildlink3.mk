# $NetBSD: buildlink3.mk,v 1.3 2022/05/02 14:54:16 jaapb Exp $

BUILDLINK_TREE+=	ocaml-stdlib-shims

.if !defined(OCAML_STDLIB_SHIMS_BUILDLINK3_MK)
OCAML_STDLIB_SHIMS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-stdlib-shims+=	ocaml-stdlib-shims>=0.2.0
BUILDLINK_ABI_DEPENDS.ocaml-stdlib-shims+=	ocaml-stdlib-shims>=0.3.0
BUILDLINK_PKGSRCDIR.ocaml-stdlib-shims?=	../../devel/ocaml-stdlib-shims
.endif	# OCAML_STDLIB_SHIMS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-stdlib-shims
