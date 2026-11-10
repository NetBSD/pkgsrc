# $NetBSD: buildlink3.mk,v 1.3 2026/11/10 08:12:07 wiz Exp $

BUILDLINK_TREE+=	mingw-w64-i686-crt-msvcrt

.if !defined(MINGW_W64_I686_CRT_MSVCRT_BUILDLINK3_MK)
MINGW_W64_I686_CRT_MSVCRT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mingw-w64-i686-crt-msvcrt+=	mingw-w64-i686-crt-msvcrt>=14.0.0
BUILDLINK_PKGSRCDIR.mingw-w64-i686-crt-msvcrt?=		../../cross/mingw-w64-i686-crt-msvcrt

.endif	# MINGW_W64_I686_CRT_MSVCRT_BUILDLINK3_MK

BUILDLINK_TREE+=	-mingw-w64-i686-crt-msvcrt
