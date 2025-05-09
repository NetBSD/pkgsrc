# $NetBSD: buildlink3.mk,v 1.10 2025/05/09 05:51:26 adam Exp $

BUILDLINK_TREE+=	wasi-libcxx

BUILDLINK_DEPMETHOD.wasi-libcxx?=	build

.if !defined(WASI_LIBCXX_BUILDLINK3_MK)
WASI_LIBCXX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wasi-libcxx+=	wasi-libcxx>=19.1.0
BUILDLINK_PKGSRCDIR.wasi-libcxx?=	../../lang/wasi-libcxx

.endif	# WASI_LIBCXX_BUILDLINK3_MK

BUILDLINK_TREE+=	-wasi-libcxx
