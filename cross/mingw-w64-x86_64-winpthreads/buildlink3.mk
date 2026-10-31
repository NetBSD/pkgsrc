# $NetBSD: buildlink3.mk,v 1.4 2026/10/31 12:20:17 js Exp $

BUILDLINK_TREE+=	mingw-w64-x86_64-winpthreads-ucrt

.if !defined(MINGW_W64_X86_64_WINPTHREADS_UCRT_BUILDLINK3_MK)
MINGW_W64_X86_64_WINPTHREADS_UCRT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mingw-w64-x86_64-winpthreads-ucrt+=	mingw-w64-x86_64-winpthreads-ucrt>=14.0.0
BUILDLINK_PKGSRCDIR.mingw-w64-x86_64-winpthreads-ucrt?=	../../cross/mingw-w64-x86_64-winpthreads

.endif	# MINGW_W64_X86_64_WINPTHREADS_UCRT_BUILDLINK3_MK

BUILDLINK_TREE+=	-mingw-w64-x86_64-winpthreads-ucrt
