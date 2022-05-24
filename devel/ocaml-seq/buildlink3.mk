# $NetBSD: buildlink3.mk,v 1.4 2022/05/24 17:48:00 jaapb Exp $

BUILDLINK_TREE+=	ocaml-seq

.if !defined(OCAML_SEQ_BUILDLINK3_MK)
OCAML_SEQ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-seq+=	ocaml-seq>=0.1
BUILDLINK_ABI_DEPENDS.ocaml-seq+=	ocaml-seq>=0.2.2
BUILDLINK_PKGSRCDIR.ocaml-seq?=		../../devel/ocaml-seq

.endif	# OCAML_SEQ_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-seq
