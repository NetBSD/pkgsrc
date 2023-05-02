# $NetBSD: buildlink3.mk,v 1.7 2023/05/02 18:19:24 nikita Exp $

BUILDLINK_TREE+=	wasi-compiler-rt

BUILDLINK_DEPMETHOD.wasi-compiler-rt?=	build

.if !defined(WASI_COMPILER_RT_BUILDLINK3_MK)
WASI_COMPILER_RT_BUILDLINK3_MK:=

# This exact version must be kept in sync with llvm, or firefox
# minimum build dependencies will be incorrect.
BUILDLINK_API_DEPENDS.wasi-compiler-rt+=	wasi-compiler-rt>=15.0.7<16
BUILDLINK_PKGSRCDIR.wasi-compiler-rt?=		../../lang/wasi-compiler-rt

.endif	# WASI_COMPILER_RT_BUILDLINK3_MK

BUILDLINK_TREE+=	-wasi-compiler-rt
