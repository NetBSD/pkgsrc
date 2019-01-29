# $NetBSD: buildlink3.mk,v 1.1 2019/01/29 14:20:26 jaapb Exp $

BUILDLINK_TREE+=	ocaml-resource-pooling

.if !defined(OCAML_RESOURCE_POOLING_BUILDLINK3_MK)
OCAML_RESOURCE_POOLING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-resource-pooling+=	ocaml-resource-pooling>=0.6
BUILDLINK_PKGSRCDIR.ocaml-resource-pooling?=	../../devel/ocaml-resource-pooling

.endif	# OCAML_RESOURCE_POOLING_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-resource-pooling
