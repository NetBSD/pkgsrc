# $NetBSD: buildlink3.mk,v 1.5 2026/11/10 08:12:07 wiz Exp $

BUILDLINK_TREE+=	mingw-w64-x86_64-crt-ucrt

.if !defined(MINGW_W64_X86_64_CRT_UCRT_BUILDLINK3_MK)
MINGW_W64_X86_64_CRT_UCRT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mingw-w64-x86_64-crt-ucrt+=	mingw-w64-x86_64-crt-ucrt>=14.0.0
BUILDLINK_PKGSRCDIR.mingw-w64-x86_64-crt-ucrt?=		../../cross/mingw-w64-x86_64-crt

.endif	# MINGW_W64_X86_64_CRT_UCRT_BUILDLINK3_MK

BUILDLINK_TREE+=	-mingw-w64-x86_64-crt-ucrt
