# $NetBSD: buildlink3.mk,v 1.3 2022/05/24 18:59:23 jaapb Exp $

BUILDLINK_TREE+=	ocaml-bos

.if !defined(OCAML_BOS_BUILDLINK3_MK)
OCAML_BOS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-bos+=	ocaml-bos>=0.2.0
BUILDLINK_ABI_DEPENDS.ocaml-bos+=	ocaml-bos>=0.2.0nb2
BUILDLINK_PKGSRCDIR.ocaml-bos?=		../../devel/ocaml-bos

.endif	# OCAML_BOS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-bos
