# $NetBSD: buildlink3.mk,v 1.9 2021/07/12 18:46:07 adam Exp $

BUILDLINK_TREE+=	libunwind

.if !defined(LIBUNWIND_BUILDLINK3_MK)
LIBUNWIND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libunwind+=	libunwind>=12.0.0
BUILDLINK_PKGSRCDIR.libunwind?=		../../lang/libunwind

.include "../../lang/llvm/buildlink3.mk"
.endif	# LIBUNWIND_BUILDLINK3_MK

BUILDLINK_TREE+=	-libunwind
