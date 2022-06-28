# $NetBSD: buildlink3.mk,v 1.2 2022/06/28 11:31:15 wiz Exp $

BUILDLINK_TREE+=	mingw-w64-x86_64-crt

.if !defined(MINGW_W64_X86_64_CRT_BUILDLINK3_MK)
MINGW_W64_X86_64_CRT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mingw-w64-x86_64-crt+=	mingw-w64-x86_64-crt>=5.0.4
BUILDLINK_ABI_DEPENDS.mingw-w64-x86_64-crt?=	mingw-w64-x86_64-crt>=9.0.0nb1
BUILDLINK_PKGSRCDIR.mingw-w64-x86_64-crt?=	../../cross/mingw-w64-x86_64-crt

.include "../../cross/mingw-w64-x86_64-headers/buildlink3.mk"
.endif	# MINGW_W64_X86_64_CRT_BUILDLINK3_MK

BUILDLINK_TREE+=	-mingw-w64-x86_64-crt
