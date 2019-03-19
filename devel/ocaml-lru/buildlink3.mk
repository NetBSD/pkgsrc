# $NetBSD: buildlink3.mk,v 1.1 2019/03/19 14:21:34 jaapb Exp $

BUILDLINK_TREE+=	ocaml-lru

.if !defined(OCAML_LRU_BUILDLINK3_MK)
OCAML_LRU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-lru+=	ocaml-lru>=0.2.0
BUILDLINK_PKGSRCDIR.ocaml-lru?=	../../devel/ocaml-lru

.endif	# OCAML_LRU_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-lru
