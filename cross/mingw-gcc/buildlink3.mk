# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/03/15 18:34:37 asau Exp $

BUILDLINK_TREE+=	mingw-gcc

.if !defined(MINGW_GCC_BUILDLINK3_MK)
MINGW_GCC_BUILDLINK3_MK:=

.include "../../cross/mingw/Makefile.common"

BUILDLINK_API_DEPENDS.mingw-gcc+=	mingw-gcc>=3.4.2
BUILDLINK_PKGSRCDIR.mingw-gcc?=		../../cross/mingw-gcc
BUILDLINK_FNAME_TRANSFORM.mingw-gcc+=	-e "s,${MINGW_TARGET}/lib,lib/,g"

.include "../../cross/mingw-binutils/buildlink3.mk"
.endif # MINGW_GCC_BUILDLINK3_MK

BUILDLINK_TREE+=	-mingw-gcc
