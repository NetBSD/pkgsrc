# $NetBSD: buildlink3.mk,v 1.18 2026/04/16 06:33:52 wiz Exp $

BUILDLINK_TREE+=	libunwind

.if !defined(LIBUNWIND_BUILDLINK3_MK)
LIBUNWIND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libunwind+=	libunwind>=21.1.0
BUILDLINK_PKGSRCDIR.libunwind?=		../../lang/libunwind

.endif	# LIBUNWIND_BUILDLINK3_MK

BUILDLINK_TREE+=	-libunwind
