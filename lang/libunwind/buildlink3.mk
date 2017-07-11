# $NetBSD: buildlink3.mk,v 1.3 2017/07/11 19:47:37 adam Exp $

BUILDLINK_TREE+=	libunwind

.if !defined(LIBUNWIND_BUILDLINK3_MK)
LIBUNWIND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libunwind+=	libunwind>=4.0.1
BUILDLINK_PKGSRCDIR.libunwind?=	../../lang/libunwind

.include "../../lang/llvm/buildlink3.mk"
.endif	# LIBUNWIND_BUILDLINK3_MK

BUILDLINK_TREE+=	-libunwind
