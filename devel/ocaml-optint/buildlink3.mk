# $NetBSD: buildlink3.mk,v 1.3 2022/05/03 19:11:52 jaapb Exp $

BUILDLINK_TREE+=	ocaml-optint

.if !defined(OCAML_OPTINT_BUILDLINK3_MK)
OCAML_OPTINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-optint+=	ocaml-optint>=0.0.2
BUILDLINK_ABI_DEPENDS.ocaml-optint+=	ocaml-optint>=0.2.0
BUILDLINK_PKGSRCDIR.ocaml-optint?=	../../devel/ocaml-optint
.endif	# OCAML_OPTINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-optint
