# $NetBSD: buildlink2.mk,v 1.3 2003/07/13 13:51:28 wiz Exp $
#
# This Makefile fragment is included by packages that use yasm.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(YASM_BUILDLINK2_MK)
YASM_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			yasm
BUILDLINK_DEPENDS.yasm?=		yasm>=0.2.2nb1
BUILDLINK_PKGSRCDIR.yasm?=		../../devel/yasm

EVAL_PREFIX+=	BUILDLINK_PREFIX.yasm=yasm
BUILDLINK_PREFIX.yasm_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.yasm+=	include/libyasm.h
BUILDLINK_FILES.yasm+=	include/libyasm/*
BUILDLINK_FILES.yasm+=	lib/libyasm.*
BUILDLINK_FILES.yasm+=	lib/yasm_basic.*
BUILDLINK_FILES.yasm+=	lib/yasm_bin.*
BUILDLINK_FILES.yasm+=	lib/yasm_coff.*
BUILDLINK_FILES.yasm+=	lib/yasm_dbg.*
BUILDLINK_FILES.yasm+=	lib/yasm_nasm.*
BUILDLINK_FILES.yasm+=	lib/yasm_null.*
BUILDLINK_FILES.yasm+=	lib/yasm_raw.*
BUILDLINK_FILES.yasm+=	lib/yasm_win32.*
BUILDLINK_FILES.yasm+=	lib/yasm_x86.*
BUILDLINK_FILES.yasm+=	lib/yasm_yapp.*

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"

BUILDLINK_TARGETS+=	yasm-buildlink

yasm-buildlink: _BUILDLINK_USE

.endif	# YASM_BUILDLINK2_MK
