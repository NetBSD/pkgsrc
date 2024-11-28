# $NetBSD: buildlink3.mk,v 1.2 2024/11/28 20:32:44 ryoon Exp $

BUILDLINK_TREE+=	mingw-w64-i686-winpthreads-ucrt

.if !defined(MINGW_W64_I686_WINPTHREADS_UCRT_BUILDLINK3_MK)
MINGW_W64_I686_WINPTHREADS_UCRT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mingw-w64-i686-winpthreads-ucrt+=	mingw-w64-i686-winpthreads-ucrt>=12.0.0
BUILDLINK_PKGSRCDIR.mingw-w64-i686-winpthreads-ucrt?=	../../cross/mingw-w64-i686-winpthreads

.endif	# MINGW_W64_I686_WINPTHREADS_UCRT_BUILDLINK3_MK

BUILDLINK_TREE+=	-mingw-w64-i686-winpthreads-ucrt
