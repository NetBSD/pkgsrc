# $NetBSD: buildlink3.mk,v 1.1 2022/05/11 11:25:03 jaapb Exp $

BUILDLINK_TREE+=	ocaml-hmap

.if !defined(OCAML_HMAP_BUILDLINK3_MK)
OCAML_HMAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-hmap+=	ocaml-hmap>=0.8.1
BUILDLINK_ABI_DEPENDS.ocaml-hmap+=	ocaml-hmap>=0.8.1
BUILDLINK_PKGSRCDIR.ocaml-hmap?=	../../devel/ocaml-hmap

.endif	# OCAML_HMAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-hmap
