# $NetBSD: buildlink3.mk,v 1.3 2024/11/28 20:01:37 ryoon Exp $

BUILDLINK_TREE+=	mingw-w64-x86_64-crt-ucrt

.if !defined(MINGW_W64_X86_64_CRT_UCRT_BUILDLINK3_MK)
MINGW_W64_X86_64_CRT_UCRT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mingw-w64-x86_64-crt-ucrt+=	mingw-w64-x86_64-crt-ucrt>=12.0.0
BUILDLINK_PKGSRCDIR.mingw-w64-x86_64-crt-ucrt?=	../../cross/mingw-w64-x86_64-crt

.endif	# MINGW_W64_X86_64_CRT_UCRT_BUILDLINK3_MK

BUILDLINK_TREE+=	-mingw-w64-x86_64-crt-ucrt
