# $NetBSD: buildlink3.mk,v 1.5 2018/12/09 20:04:39 adam Exp $

BUILDLINK_TREE+=	libunwind

.if !defined(LIBUNWIND_BUILDLINK3_MK)
LIBUNWIND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libunwind+=	libunwind>=7.0.0
BUILDLINK_PKGSRCDIR.libunwind?=		../../lang/libunwind

.include "../../lang/llvm/buildlink3.mk"
.endif	# LIBUNWIND_BUILDLINK3_MK

BUILDLINK_TREE+=	-libunwind
