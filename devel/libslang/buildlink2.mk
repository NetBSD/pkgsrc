# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:14 jlam Exp $

.if !defined(LIBSLANG_BUILDLINK2_MK)
LIBSLANG_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libslang
BUILDLINK_DEPENDS.libslang?=	libslang>=1.4.4
BUILDLINK_PKGSRCDIR.libslang?=	../../devel/libslang

EVAL_PREFIX+=			BUILDLINK_PREFIX.libslang=libslang
BUILDLINK_PREFIX.libslang_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libslang=	include/slcurses.h
BUILDLINK_FILES.libslang+=	include/slang.h
BUILDLINK_FILES.libslang+=	lib/libslang.*

BUILDLINK_TARGETS+=	libslang-buildlink

libslang-buildlink: _BUILDLINK_USE

.endif	# LIBSLANG_BUILDLINK2_MK
