# $NetBSD: buildlink3.mk,v 1.2 2019/11/03 10:39:25 rillig Exp $

BUILDLINK_TREE+=	ocaml-psq

.if !defined(OCAML_PSQ_BUILDLINK3_MK)
OCAML_PSQ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-psq+=	ocaml-psq>=0.1.0
BUILDLINK_PKGSRCDIR.ocaml-psq?=		../../devel/ocaml-psq
.endif	# OCAML_PSQ_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-psq
