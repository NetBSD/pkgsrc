# $NetBSD: buildlink3.mk,v 1.1 2026/11/09 23:05:13 js Exp $

BUILDLINK_TREE+=	mingw-w64-i686-crt-crtdll

.if !defined(MINGW_W64_I686_CRT_CRTDLL_BUILDLINK3_MK)
MINGW_W64_I686_CRT_CRTDLL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mingw-w64-i686-crt-crtdll+=	mingw-w64-i686-crt-crtdll>=14.0.0
BUILDLINK_PKGSRCDIR.mingw-w64-i686-crt-crtdll?=	../../cross/mingw-w64-i686-crt-crtdll

.endif	# MINGW_W64_I686_CRT_CRTDLL_BUILDLINK3_MK

BUILDLINK_TREE+=	-mingw-w64-i686-crt-crtdll
