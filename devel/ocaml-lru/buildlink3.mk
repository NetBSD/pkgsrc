# $NetBSD: buildlink3.mk,v 1.3 2022/05/24 18:59:26 jaapb Exp $

BUILDLINK_TREE+=	ocaml-lru

.if !defined(OCAML_LRU_BUILDLINK3_MK)
OCAML_LRU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-lru+=	ocaml-lru>=0.2.0
BUILDLINK_ABI_DEPENDS.ocaml-lru+=	ocaml-lru>=0.2.0nb2
BUILDLINK_PKGSRCDIR.ocaml-lru?=		../../devel/ocaml-lru

.endif	# OCAML_LRU_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-lru
