# $NetBSD: buildlink3.mk,v 1.1 2019/03/12 17:47:09 jaapb Exp $

BUILDLINK_TREE+=	ocaml-optint

.if !defined(OCAML_OPTINT_BUILDLINK3_MK)
OCAML_OPTINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-optint+=	ocaml-optint>=0.0.2
BUILDLINK_PKGSRCDIR.ocaml-optint?=	../../devel/ocaml-optint
.endif	# OCAML_OPTINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-optint
