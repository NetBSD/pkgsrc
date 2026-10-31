# $NetBSD: buildlink3.mk,v 1.2 2026/10/31 12:20:16 js Exp $

BUILDLINK_TREE+=	mingw-w64-i686-crt-msvcrt

.if !defined(MINGW_W64_I686_CRT_MSVCRT_BUILDLINK3_MK)
MINGW_W64_I686_CRT_MSVCRT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mingw-w64-i686-crt-msvcrt+=	mingw-w64-i686-crt-msvcrt>=14.0.0
BUILDLINK_PKGSRCDIR.mingw-w64-i686-crt-msvcrt?=	../../cross/mingw-w64-i686-crt-msvcrt

.endif	# MINGW_W64_I686_CRT_MSVCRT_BUILDLINK3_MK

BUILDLINK_TREE+=	-mingw-w64-i686-crt-msvcrt
