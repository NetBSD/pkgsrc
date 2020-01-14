# $NetBSD: buildlink3.mk,v 1.7 2020/01/14 22:14:42 jaapb Exp $

BUILDLINK_TREE+=	ocaml-compiler-libs

.if !defined(OCAML_COMPILER_LIBS_BUILDLINK3_MK)
OCAML_COMPILER_LIBS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-compiler-libs+=	ocaml-compiler-libs>=0.9.0
BUILDLINK_ABI_DEPENDS.ocaml-compiler-libs+=	ocaml-compiler-libs>=0.12.1
BUILDLINK_PKGSRCDIR.ocaml-compiler-libs?=	../../devel/ocaml-compiler-libs
.endif	# OCAML_COMPILER_LIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-compiler-libs
