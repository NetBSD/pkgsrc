# $NetBSD: buildlink3.mk,v 1.1 2018/01/10 16:29:44 jaapb Exp $

BUILDLINK_TREE+=	ocaml-num

.if !defined(OCAML_NUM_BUILDLINK3_MK)
OCAML_NUM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-num+=	ocaml-num>=1.1
BUILDLINK_PKGSRCDIR.ocaml-num?=	../../math/ocaml-num
.endif	# OCAML_NUM_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-num
