# $NetBSD: buildlink3.mk,v 1.2 2022/06/04 00:34:31 gutteridge Exp $

BUILDLINK_TREE+=	wasi-libcxx

BUILDLINK_DEPMETHOD.wasi-libcxx?=	build

.if !defined(WASI_LIBCXX_BUILDLINK3_MK)
WASI_LIBCXX_BUILDLINK3_MK:=

# This exact version must be kept in sync with llvm, or firefox
# minimum build dependencies will be incorrect.
BUILDLINK_API_DEPENDS.wasi-libcxx+=	wasi-libcxx>=13.0.1
BUILDLINK_PKGSRCDIR.wasi-libcxx?=	../../lang/wasi-libcxx

.endif	# WASI_LIBCXX_BUILDLINK3_MK

BUILDLINK_TREE+=	-wasi-libcxx
