# $NetBSD: buildlink3.mk,v 1.9 2023/10/06 19:15:21 adam Exp $

BUILDLINK_TREE+=	libcxxabi

.if !defined(LIBCXXABI_BUILDLINK3_MK)
LIBCXXABI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcxxabi+=	libcxxabi>=16.0.0<17
BUILDLINK_PKGSRCDIR.libcxxabi?=		../../lang/libcxxabi

.include "../../lang/llvm/buildlink3.mk"
.include "../../lang/libunwind/buildlink3.mk"
.endif	# LIBCXXABI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcxxabi
