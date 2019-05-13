# $NetBSD: buildlink3.mk,v 1.1 2019/05/13 10:54:47 jaapb Exp $

BUILDLINK_TREE+=	ocaml-mmap

.if !defined(OCAML_MMAP_BUILDLINK3_MK)
OCAML_MMAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-mmap+=	ocaml-mmap>=1.1.0
BUILDLINK_PKGSRCDIR.ocaml-mmap?=	../../devel/ocaml-mmap
.endif	# OCAML_MMAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-mmap
