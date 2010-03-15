# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/03/15 18:34:41 asau Exp $

BUILDLINK_TREE+=	mingw-w32api-bin

.if !defined(MINGW_W32API_BIN_BUILDLINK3_MK)
MINGW_W32API_BIN_BUILDLINK3_MK:=

.include "../../cross/mingw/Makefile.common"

BUILDLINK_API_DEPENDS.mingw-w32api-bin+=	mingw-w32api-bin>=3.1
BUILDLINK_PKGSRCDIR.mingw-w32api-bin?=		../../cross/mingw-w32api-bin
BUILDLINK_FNAME_TRANSFORM.mingw-w32api-bin+=	-e "s,${MINGW_TARGET}/include,include/,g"
BUILDLINK_FNAME_TRANSFORM.mingw-w32api-bin+=	-e "s,${MINGW_TARGET}/lib,lib/,g"
.endif # MINGW_W32API_BIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-mingw-w32api-bin
