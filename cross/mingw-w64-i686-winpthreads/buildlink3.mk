# $NetBSD: buildlink3.mk,v 1.1 2019/09/18 15:32:47 ryoon Exp $

BUILDLINK_TREE+=	mingw-w64-i686-winpthreads

.if !defined(MINGW_W64_I686_WINPTHREADS_BUILDLINK3_MK)
MINGW_W64_I686_WINPTHREADS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mingw-w64-i686-winpthreads+=	mingw-w64-i686-winpthreads>=6.0.0
BUILDLINK_PKGSRCDIR.mingw-w64-i686-winpthreads?=	../../cross/mingw-w64-i686-winpthreads

.endif	# MINGW_W64_I686_WINPTHREADS_BUILDLINK3_MK

BUILDLINK_TREE+=	-mingw-w64-i686-winpthreads
