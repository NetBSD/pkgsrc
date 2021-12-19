# $NetBSD: buildlink3.mk,v 1.1 2021/12/19 14:12:20 ryoon Exp $

BUILDLINK_TREE+=	wasi-libcxx

BUILDLINK_DEPMETHOD.wasi-libcxx?=	build

.if !defined(WASI_LIBCXX_BUILDLINK3_MK)
WASI_LIBCXX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wasi-libcxx+=	wasi-libcxx>=13.0.0
BUILDLINK_PKGSRCDIR.wasi-libcxx?=	../../lang/wasi-libcxx

.endif	# WASI_LIBCXX_BUILDLINK3_MK

BUILDLINK_TREE+=	-wasi-libcxx
