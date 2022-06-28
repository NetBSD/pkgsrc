# $NetBSD: buildlink3.mk,v 1.2 2022/06/28 11:31:15 wiz Exp $

BUILDLINK_TREE+=	mingw-w64-x86_64-winpthreads

.if !defined(MINGW_W64_X86_64_WINPTHREADS_BUILDLINK3_MK)
MINGW_W64_X86_64_WINPTHREADS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mingw-w64-x86_64-winpthreads+=	mingw-w64-x86_64-winpthreads>=6.0.0
BUILDLINK_ABI_DEPENDS.mingw-w64-x86_64-winpthreads?=	mingw-w64-x86_64-winpthreads>=9.0.0nb1
BUILDLINK_PKGSRCDIR.mingw-w64-x86_64-winpthreads?=	../../cross/mingw-w64-x86_64-winpthreads

.endif	# MINGW_W64_X86_64_WINPTHREADS_BUILDLINK3_MK

BUILDLINK_TREE+=	-mingw-w64-x86_64-winpthreads
