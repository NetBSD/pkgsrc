# $NetBSD: buildlink3.mk,v 1.17 2026/03/25 22:56:27 wiz Exp $

BUILDLINK_TREE+=	libunwind

.if !defined(LIBUNWIND_BUILDLINK3_MK)
LIBUNWIND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libunwind+=	libunwind>=20.1.0
BUILDLINK_PKGSRCDIR.libunwind?=		../../lang/libunwind

.endif	# LIBUNWIND_BUILDLINK3_MK

BUILDLINK_TREE+=	-libunwind
