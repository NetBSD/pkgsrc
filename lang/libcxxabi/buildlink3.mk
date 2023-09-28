# $NetBSD: buildlink3.mk,v 1.8 2023/09/28 21:32:13 joerg Exp $

BUILDLINK_TREE+=	libcxxabi

.if !defined(LIBCXXABI_BUILDLINK3_MK)
LIBCXXABI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcxxabi+=	libcxxabi>=14.0.0<16
BUILDLINK_PKGSRCDIR.libcxxabi?=		../../lang/libcxxabi

.include "../../lang/libunwind/buildlink3.mk"
.endif	# LIBCXXABI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcxxabi
