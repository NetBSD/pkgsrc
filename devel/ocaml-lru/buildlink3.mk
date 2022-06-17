# $NetBSD: buildlink3.mk,v 1.4 2022/06/17 13:01:24 jaapb Exp $

BUILDLINK_TREE+=	ocaml-lru

.if !defined(OCAML_LRU_BUILDLINK3_MK)
OCAML_LRU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-lru+=	ocaml-lru>=0.3.0
BUILDLINK_ABI_DEPENDS.ocaml-lru+=	ocaml-lru>=0.3.0
BUILDLINK_PKGSRCDIR.ocaml-lru?=		../../devel/ocaml-lru

.endif	# OCAML_LRU_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-lru
