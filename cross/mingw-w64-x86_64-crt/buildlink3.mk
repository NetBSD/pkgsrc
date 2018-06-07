# $NetBSD: buildlink3.mk,v 1.1 2018/06/07 19:19:46 ryoon Exp $

BUILDLINK_TREE+=	mingw-w64-x86_64-crt

.if !defined(MINGW_W64_X86_64_CRT_BUILDLINK3_MK)
MINGW_W64_X86_64_CRT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mingw-w64-x86_64-crt+=	mingw-w64-x86_64-crt>=5.0.4
BUILDLINK_PKGSRCDIR.mingw-w64-x86_64-crt?=	../../cross/mingw-w64-x86_64-crt

.include "../../cross/mingw-w64-x86_64-headers/buildlink3.mk"
.endif	# MINGW_W64_X86_64_CRT_BUILDLINK3_MK

BUILDLINK_TREE+=	-mingw-w64-x86_64-crt
