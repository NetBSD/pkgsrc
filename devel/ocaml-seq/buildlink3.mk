# $NetBSD: buildlink3.mk,v 1.2 2019/11/03 10:39:26 rillig Exp $

BUILDLINK_TREE+=	ocaml-seq

.if !defined(OCAML_SEQ_BUILDLINK3_MK)
OCAML_SEQ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-seq+=	ocaml-seq>=0.1
BUILDLINK_PKGSRCDIR.ocaml-seq?=		../../devel/ocaml-seq

.endif	# OCAML_SEQ_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-seq
