# $NetBSD: buildlink3.mk,v 1.2 2019/11/03 10:39:23 rillig Exp $

BUILDLINK_TREE+=	ocaml-lru

.if !defined(OCAML_LRU_BUILDLINK3_MK)
OCAML_LRU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-lru+=	ocaml-lru>=0.2.0
BUILDLINK_PKGSRCDIR.ocaml-lru?=		../../devel/ocaml-lru

.endif	# OCAML_LRU_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-lru
