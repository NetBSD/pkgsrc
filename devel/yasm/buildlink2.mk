# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/04/09 15:59:53 jmmv Exp $
#
# This Makefile fragment is included by packages that use yasm.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(YASM_BUILDLINK2_MK)
YASM_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			yasm
BUILDLINK_DEPENDS.yasm?=		yasm>=0.2.0
BUILDLINK_PKGSRCDIR.yasm?=		../../devel/yasm

EVAL_PREFIX+=	BUILDLINK_PREFIX.yasm=yasm
BUILDLINK_PREFIX.yasm_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.yasm+=	include/libyasm.h
BUILDLINK_FILES.yasm+=	include/libyasm/*
BUILDLINK_FILES.yasm+=	lib/libyasm.*
BUILDLINK_FILES.yasm+=	lib/yasm-basic.*
BUILDLINK_FILES.yasm+=	lib/yasm-bin.*
BUILDLINK_FILES.yasm+=	lib/yasm-coff.*
BUILDLINK_FILES.yasm+=	lib/yasm-dbg.*
BUILDLINK_FILES.yasm+=	lib/yasm-nasm.*
BUILDLINK_FILES.yasm+=	lib/yasm-null.*
BUILDLINK_FILES.yasm+=	lib/yasm-raw.*
BUILDLINK_FILES.yasm+=	lib/yasm-win32.*
BUILDLINK_FILES.yasm+=	lib/yasm-x86.*
BUILDLINK_FILES.yasm+=	lib/yasm-yapp.*

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"

BUILDLINK_TARGETS+=	yasm-buildlink

yasm-buildlink: _BUILDLINK_USE

.endif	# YASM_BUILDLINK2_MK
