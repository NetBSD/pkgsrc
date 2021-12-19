# $NetBSD: buildlink3.mk,v 1.1 2021/12/19 13:38:56 ryoon Exp $

BUILDLINK_TREE+=	wasi-libc

BUILDLINK_DEPMETHOD.wasi-libc?=	build

.if !defined(WASI_LIBC_BUILDLINK3_MK)
WASI_LIBC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wasi-libc+=	wasi-libc>=0.0.0pre20210923
BUILDLINK_PKGSRCDIR.wasi-libc?=		../../lang/wasi-libc

.endif	# WASI_LIBC_BUILDLINK3_MK

BUILDLINK_TREE+=	-wasi-libc
