# $NetBSD: buildlink3.mk,v 1.1 2022/05/05 09:02:05 jaapb Exp $

BUILDLINK_TREE+=	ocaml-intrinsics

.if !defined(OCAML_INTRINSICS_BUILDLINK3_MK)
OCAML_INTRINSICS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-intrinsics+=	ocaml-intrinsics>=0.15.2
BUILDLINK_PKGSRCDIR.ocaml-intrinsics?=		../../devel/ocaml-intrinsics

.endif	# OCAML_INTRINSICS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-intrinsics
