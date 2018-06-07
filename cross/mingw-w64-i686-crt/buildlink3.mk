# $NetBSD: buildlink3.mk,v 1.1 2018/06/07 19:32:13 ryoon Exp $

BUILDLINK_TREE+=	mingw-w64-i686-crt

.if !defined(MINGW_W64_I686_CRT_BUILDLINK3_MK)
MINGW_W64_I686_CRT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mingw-w64-i686-crt+=	mingw-w64-i686-crt>=5.0.4
BUILDLINK_PKGSRCDIR.mingw-w64-i686-crt?=	../../cross/mingw-w64-i686-crt

.include "../../cross/mingw-w64-i686-headers/buildlink3.mk"
.endif	# MINGW_W64_I686_CRT_BUILDLINK3_MK

BUILDLINK_TREE+=	-mingw-w64-i686-crt
