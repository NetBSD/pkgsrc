# $NetBSD: buildlink3.mk,v 1.14 2026/03/25 22:56:26 wiz Exp $

BUILDLINK_TREE+=	libcxxabi

.if !defined(LIBCXXABI_BUILDLINK3_MK)
LIBCXXABI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcxxabi+=	libcxxabi>=20.1.0
BUILDLINK_PKGSRCDIR.libcxxabi?=		../../lang/libcxxabi

.include "../../lang/llvm/buildlink3.mk"
.include "../../lang/libunwind/buildlink3.mk"
.endif	# LIBCXXABI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcxxabi
