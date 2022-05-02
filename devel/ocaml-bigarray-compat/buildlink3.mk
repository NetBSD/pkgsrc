# $NetBSD: buildlink3.mk,v 1.2 2022/05/02 13:23:44 jaapb Exp $

BUILDLINK_TREE+=	ocaml-bigarray-compat

.if !defined(OCAML_BIGARRAY_COMPAT_BUILDLINK3_MK)
OCAML_BIGARRAY_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-bigarray-compat+=	ocaml-bigarray-compat>=1.0.0
BUILDLINK_ABI_DEPENDS.ocaml-bigarray-compat+=	ocaml-bigarray-compat>=1.1.0
BUILDLINK_PKGSRCDIR.ocaml-bigarray-compat?=	../../devel/ocaml-bigarray-compat
.endif	# OCAML_BIGARRAY_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-bigarray-compat
