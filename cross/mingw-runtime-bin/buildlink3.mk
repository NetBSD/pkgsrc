# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/03/15 18:34:39 asau Exp $

BUILDLINK_TREE+=	mingw-runtime-bin

.if !defined(MINGW_RUNTIME_BIN_BUILDLINK3_MK)
MINGW_RUNTIME_BIN_BUILDLINK3_MK:=

.include "../../cross/mingw/Makefile.common"

BUILDLINK_API_DEPENDS.mingw-runtime-bin+=	mingw-runtime-bin>=3.5
BUILDLINK_PKGSRCDIR.mingw-runtime-bin?=		../../cross/mingw-runtime-bin
BUILDLINK_FNAME_TRANSFORM.mingw-runtime-bin+=	-e "s,${MINGW_TARGET}/lib,lib/,g"
.endif # MINGW_RUNTIME_BIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-mingw-runtime-bin
