# $NetBSD: buildlink3.mk,v 1.1 2018/08/09 14:13:25 jperkin Exp $

BUILDLINK_TREE+=	libcxxabi

.if !defined(LIBCXXABI_BUILDLINK3_MK)
LIBCXXABI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcxxabi+=	libcxxabi>=6.0.1
BUILDLINK_PKGSRCDIR.libcxxabi?=		../../lang/libcxxabi

.include "../../lang/llvm/buildlink3.mk"
.endif	# LIBCXXABI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcxxabi
