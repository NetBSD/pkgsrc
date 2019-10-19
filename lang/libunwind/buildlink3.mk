# $NetBSD: buildlink3.mk,v 1.7 2019/10/19 13:59:06 adam Exp $

BUILDLINK_TREE+=	libunwind

.if !defined(LIBUNWIND_BUILDLINK3_MK)
LIBUNWIND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libunwind+=	libunwind>=9.0.0
BUILDLINK_PKGSRCDIR.libunwind?=		../../lang/libunwind

.include "../../lang/llvm/buildlink3.mk"
.endif	# LIBUNWIND_BUILDLINK3_MK

BUILDLINK_TREE+=	-libunwind
