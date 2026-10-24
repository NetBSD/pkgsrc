# $NetBSD: buildlink3.mk,v 1.1 2026/10/24 17:25:39 alnsn Exp $

BUILDLINK_TREE+=	ocaml-ctypes

.if !defined(OCAML_CTYPES_BUILDLINK3_MK)
OCAML_CTYPES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-ctypes+=	ocaml-ctypes>=0.21.1
BUILDLINK_ABI_DEPENDS.ocaml-ctypes+=	ocaml-ctypes>=0.21.1
BUILDLINK_PKGSRCDIR.ocaml-ctypes?=	../../devel/ocaml-ctypes

.endif	# OCAML_CTYPES_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-ctypes
