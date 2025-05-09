# $NetBSD: buildlink3.mk,v 1.16 2025/05/09 05:51:25 adam Exp $

BUILDLINK_TREE+=	libunwind

.if !defined(LIBUNWIND_BUILDLINK3_MK)
LIBUNWIND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libunwind+=	libunwind>=19.1.0
BUILDLINK_PKGSRCDIR.libunwind?=		../../lang/libunwind

.endif	# LIBUNWIND_BUILDLINK3_MK

BUILDLINK_TREE+=	-libunwind
