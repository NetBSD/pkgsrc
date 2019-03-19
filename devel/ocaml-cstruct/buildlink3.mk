# $NetBSD: buildlink3.mk,v 1.1 2019/03/19 11:11:31 jaapb Exp $

BUILDLINK_TREE+=	ocaml-cstruct

.if !defined(OCAML_CSTRUCT_BUILDLINK3_MK)
OCAML_CSTRUCT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-cstruct+=	ocaml-cstruct>=3.7.0
BUILDLINK_PKGSRCDIR.ocaml-cstruct?=	../../devel/ocaml-cstruct
.endif	# OCAML_CSTRUCT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-cstruct
