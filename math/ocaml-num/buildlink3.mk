# $NetBSD: buildlink3.mk,v 1.3 2019/11/02 16:16:20 rillig Exp $

BUILDLINK_TREE+=	ocaml-num

.if !defined(OCAML_NUM_BUILDLINK3_MK)
OCAML_NUM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-num+=	ocaml-num>=1.1
BUILDLINK_ABI_DEPENDS.ocaml-num+=	ocaml-num>=1.1nb2
BUILDLINK_PKGSRCDIR.ocaml-num?=		../../math/ocaml-num
.endif	# OCAML_NUM_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-num
