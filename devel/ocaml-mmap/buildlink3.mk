# $NetBSD: buildlink3.mk,v 1.2 2022/05/02 13:33:00 jaapb Exp $

BUILDLINK_TREE+=	ocaml-mmap

.if !defined(OCAML_MMAP_BUILDLINK3_MK)
OCAML_MMAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-mmap+=	ocaml-mmap>=1.1.0
BUILDLINK_ABI_DEPENDS.ocaml-mmap+=	ocaml-mmap>=1.2.0
BUILDLINK_PKGSRCDIR.ocaml-mmap?=	../../devel/ocaml-mmap
.endif	# OCAML_MMAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-mmap
