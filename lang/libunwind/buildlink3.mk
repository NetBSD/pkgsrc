# $NetBSD: buildlink3.mk,v 1.11 2022/08/12 08:39:56 pin Exp $

BUILDLINK_TREE+=	libunwind

.if !defined(LIBUNWIND_BUILDLINK3_MK)
LIBUNWIND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libunwind+=	libunwind>=14.0.0
BUILDLINK_PKGSRCDIR.libunwind?=		../../lang/libunwind

.endif	# LIBUNWIND_BUILDLINK3_MK

BUILDLINK_TREE+=	-libunwind
