# $NetBSD: buildlink3.mk,v 1.2 2022/05/05 11:40:16 jaapb Exp $

BUILDLINK_TREE+=	ocaml-cstruct

.if !defined(OCAML_CSTRUCT_BUILDLINK3_MK)
OCAML_CSTRUCT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-cstruct+=	ocaml-cstruct>=6.1.0
BUILDLINK_ABI_DEPENDS.ocaml-cstruct+=	ocaml-cstruct>=6.1.0
BUILDLINK_PKGSRCDIR.ocaml-cstruct?=	../../devel/ocaml-cstruct
.endif	# OCAML_CSTRUCT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-cstruct
