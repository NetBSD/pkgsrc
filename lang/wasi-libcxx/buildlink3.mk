# $NetBSD: buildlink3.mk,v 1.9 2024/07/06 15:45:09 adam Exp $

BUILDLINK_TREE+=	wasi-libcxx

BUILDLINK_DEPMETHOD.wasi-libcxx?=	build

.if !defined(WASI_LIBCXX_BUILDLINK3_MK)
WASI_LIBCXX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wasi-libcxx+=	wasi-libcxx>=18.0.0
BUILDLINK_PKGSRCDIR.wasi-libcxx?=	../../lang/wasi-libcxx

.endif	# WASI_LIBCXX_BUILDLINK3_MK

BUILDLINK_TREE+=	-wasi-libcxx
