# $NetBSD: buildlink3.mk,v 1.1 2019/03/19 14:19:47 jaapb Exp $

BUILDLINK_TREE+=	ocaml-psq

.if !defined(OCAML_PSQ_BUILDLINK3_MK)
OCAML_PSQ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-psq+=	ocaml-psq>=0.1.0
BUILDLINK_PKGSRCDIR.ocaml-psq?=	../../devel/ocaml-psq
.endif	# OCAML_PSQ_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-psq
