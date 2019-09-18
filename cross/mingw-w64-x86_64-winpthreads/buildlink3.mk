# $NetBSD: buildlink3.mk,v 1.1 2019/09/18 15:36:43 ryoon Exp $

BUILDLINK_TREE+=	mingw-w64-x86_64-winpthreads

.if !defined(MINGW_W64_X86_64_WINPTHREADS_BUILDLINK3_MK)
MINGW_W64_X86_64_WINPTHREADS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mingw-w64-x86_64-winpthreads+=	mingw-w64-x86_64-winpthreads>=6.0.0
BUILDLINK_PKGSRCDIR.mingw-w64-x86_64-winpthreads?=	../../cross/mingw-w64-x86_64-winpthreads

.endif	# MINGW_W64_X86_64_WINPTHREADS_BUILDLINK3_MK

BUILDLINK_TREE+=	-mingw-w64-x86_64-winpthreads
