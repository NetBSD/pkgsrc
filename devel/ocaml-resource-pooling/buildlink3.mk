# $NetBSD: buildlink3.mk,v 1.3 2022/05/24 18:51:51 jaapb Exp $

BUILDLINK_TREE+=	ocaml-resource-pooling

.if !defined(OCAML_RESOURCE_POOLING_BUILDLINK3_MK)
OCAML_RESOURCE_POOLING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-resource-pooling+=	ocaml-resource-pooling>=1.0
BUILDLINK_ABI_DEPENDS.ocaml-resource-pooling+=	ocaml-resource-pooling>=1.1nb2
BUILDLINK_PKGSRCDIR.ocaml-resource-pooling?=	../../devel/ocaml-resource-pooling

.endif	# OCAML_RESOURCE_POOLING_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-resource-pooling
