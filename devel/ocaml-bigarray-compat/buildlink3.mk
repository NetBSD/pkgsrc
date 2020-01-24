# $NetBSD: buildlink3.mk,v 1.1 2020/01/24 16:20:47 jaapb Exp $

BUILDLINK_TREE+=	ocaml-bigarray-compat

.if !defined(OCAML_BIGARRAY_COMPAT_BUILDLINK3_MK)
OCAML_BIGARRAY_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-bigarray-compat+=	ocaml-bigarray-compat>=1.0.0
BUILDLINK_PKGSRCDIR.ocaml-bigarray-compat?=	../../devel/ocaml-bigarray-compat
.endif	# OCAML_BIGARRAY_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-bigarray-compat
