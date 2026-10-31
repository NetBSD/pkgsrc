# $NetBSD: buildlink3.mk,v 1.2 2026/10/31 12:20:17 js Exp $

BUILDLINK_TREE+=	mingw-w64-x86_64-headers-msvcrt

.if !defined(MINGW_W64_X86_64_HEADERS_MSVCRT_BUILDLINK3_MK)
MINGW_W64_X86_64_HEADERS_MSVCRT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mingw-w64-x86_64-headers-msvcrt+=	mingw-w64-x86_64-headers-msvcrt>=14.0.0
BUILDLINK_PKGSRCDIR.mingw-w64-x86_64-headers-msvcrt?=	../../cross/mingw-w64-x86_64-headers-msvcrt
.endif	# MINGW_W64_X86_64_HEADERS_MSVCRT_BUILDLINK3_MK

BUILDLINK_TREE+=	-mingw-w64-x86_64-headers-msvcrt
