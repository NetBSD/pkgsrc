# $NetBSD: buildlink3.mk,v 1.5 2022/12/15 01:10:02 gutteridge Exp $

BUILDLINK_TREE+=	wasi-compiler-rt

BUILDLINK_DEPMETHOD.wasi-compiler-rt?=	build

.if !defined(WASI_COMPILER_RT_BUILDLINK3_MK)
WASI_COMPILER_RT_BUILDLINK3_MK:=

# This exact version must be kept in sync with llvm, or firefox
# minimum build dependencies will be incorrect.
BUILDLINK_API_DEPENDS.wasi-compiler-rt+=	wasi-compiler-rt>=15.0.6
BUILDLINK_PKGSRCDIR.wasi-compiler-rt?=		../../lang/wasi-compiler-rt

.endif	# WASI_COMPILER_RT_BUILDLINK3_MK

BUILDLINK_TREE+=	-wasi-compiler-rt
