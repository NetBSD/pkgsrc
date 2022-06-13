# $NetBSD: buildlink3.mk,v 1.4 2022/06/13 09:10:05 jaapb Exp $

BUILDLINK_TREE+=	ocaml-psq

.if !defined(OCAML_PSQ_BUILDLINK3_MK)
OCAML_PSQ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-psq+=	ocaml-psq>=0.2.0
BUILDLINK_ABI_DEPENDS.ocaml-psq+=	ocaml-psq>=0.2.0
BUILDLINK_PKGSRCDIR.ocaml-psq?=		../../devel/ocaml-psq
.endif	# OCAML_PSQ_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-psq
