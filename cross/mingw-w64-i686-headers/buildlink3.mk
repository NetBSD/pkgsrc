# $NetBSD: buildlink3.mk,v 1.2 2024/11/28 20:10:27 ryoon Exp $

BUILDLINK_TREE+=	mingw-w64-i686-headers-ucrt

.if !defined(MINGW_W64_I686_HEADERS_UCRT_BUILDLINK3_MK)
MINGW_W64_I686_HEADERS_UCRT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mingw-w64-i686-headers-ucrt+=	mingw-w64-i686-headers-ucrt>=12.0.0
BUILDLINK_PKGSRCDIR.mingw-w64-i686-headers-ucrt?=	../../cross/mingw-w64-i686-headers
.endif	# MINGW_W64_I686_HEADERS_UCRT_BUILDLINK3_MK

BUILDLINK_TREE+=	-mingw-w64-i686-headers-ucrt
