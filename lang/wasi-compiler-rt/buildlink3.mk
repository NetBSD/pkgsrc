# $NetBSD: buildlink3.mk,v 1.2 2022/02/04 12:12:27 wiz Exp $

BUILDLINK_TREE+=	wasi-compiler-rt

BUILDLINK_DEPMETHOD.wasi-compiler-rt?=	build

.if !defined(WASI_COMPILER_RT_BUILDLINK3_MK)
WASI_COMPILER_RT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wasi-compiler-rt+=	wasi-compiler-rt>=13.0.0
BUILDLINK_PKGSRCDIR.wasi-compiler-rt?=		../../lang/wasi-compiler-rt

.endif	# WASI_COMPILER_RT_BUILDLINK3_MK

BUILDLINK_TREE+=	-wasi-compiler-rt
