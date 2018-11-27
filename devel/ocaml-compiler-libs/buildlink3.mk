# $NetBSD: buildlink3.mk,v 1.5 2018/11/27 18:54:05 jaapb Exp $

BUILDLINK_TREE+=	ocaml-compiler-libs

.if !defined(OCAML_COMPILER_LIBS_BUILDLINK3_MK)
OCAML_COMPILER_LIBS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ocaml-compiler-libs+=	ocaml-compiler-libs>=0.9.0
BUILDLINK_ABI_DEPENDS.ocaml-compiler-libs+=	ocaml-compiler-libs>=0.11.0nb3
BUILDLINK_PKGSRCDIR.ocaml-compiler-libs?=	../../devel/ocaml-compiler-libs
.endif	# OCAML_COMPILER_LIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-ocaml-compiler-libs
