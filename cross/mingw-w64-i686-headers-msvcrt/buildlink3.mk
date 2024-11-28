# $NetBSD: buildlink3.mk,v 1.1 2024/11/28 20:14:05 ryoon Exp $

BUILDLINK_TREE+=	mingw-w64-i686-headers-msvcrt

.if !defined(MINGW_W64_I686_HEADERS_MSVCRT_BUILDLINK3_MK)
MINGW_W64_I686_HEADERS_MSVCRT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mingw-w64-i686-headers-msvcrt+=	mingw-w64-i686-headers-msvcrt>=12.0.0
BUILDLINK_PKGSRCDIR.mingw-w64-i686-headers-msvcrt?=	../../cross/mingw-w64-i686-headers-msvcrt
.endif	# MINGW_W64_I686_HEADERS_MSVCRT_BUILDLINK3_MK

BUILDLINK_TREE+=	-mingw-w64-i686-headers-msvcrt
