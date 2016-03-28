# $NetBSD: buildlink3.mk,v 1.1 2016/03/28 12:56:03 kamil Exp $

BUILDLINK_TREE+=	libunwind

.if !defined(LIBUNWIND_BUILDLINK3_MK)
LIBUNWIND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libunwind+=	libunwind>=3.8.0
BUILDLINK_PKGSRCDIR.libunwind?=	../../lang/libunwind

.include "../../lang/llvm/buildlink3.mk"
.endif	# LIBUNWIND_BUILDLINK3_MK

BUILDLINK_TREE+=	-libunwind
