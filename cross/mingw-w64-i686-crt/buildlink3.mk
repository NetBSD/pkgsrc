# $NetBSD: buildlink3.mk,v 1.2 2024/11/28 20:02:52 ryoon Exp $

BUILDLINK_TREE+=	mingw-w64-i686-crt-ucrt

.if !defined(MINGW_W64_I686_CRT_UCRT_BUILDLINK3_MK)
MINGW_W64_I686_CRT_UCRT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mingw-w64-i686-crt-ucrt+=	mingw-w64-i686-crt-ucrt>=12.0.0
BUILDLINK_PKGSRCDIR.mingw-w64-i686-crt-ucrt?=	../../cross/mingw-w64-i686-crt

.endif	# MINGW_W64_I686_CRT_UCRT_BUILDLINK3_MK

BUILDLINK_TREE+=	-mingw-w64-i686-crt-ucrt
