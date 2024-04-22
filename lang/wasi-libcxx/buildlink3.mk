# $NetBSD: buildlink3.mk,v 1.8 2024/04/22 07:26:42 adam Exp $

BUILDLINK_TREE+=	wasi-libcxx

BUILDLINK_DEPMETHOD.wasi-libcxx?=	build

.if !defined(WASI_LIBCXX_BUILDLINK3_MK)
WASI_LIBCXX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wasi-libcxx+=	wasi-libcxx>=17.0.0<18
BUILDLINK_PKGSRCDIR.wasi-libcxx?=	../../lang/wasi-libcxx

.endif	# WASI_LIBCXX_BUILDLINK3_MK

BUILDLINK_TREE+=	-wasi-libcxx
