# $NetBSD: buildlink2.mk,v 1.3 2003/12/08 14:33:47 wiz Exp $

.if !defined(LIBAO_BUILDLINK2_MK)
LIBAO_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libao
BUILDLINK_DEPENDS.libao?=	libao>=0.8.4
BUILDLINK_PKGSRCDIR.libao?=	../../audio/libao

EVAL_PREFIX+=		BUILDLINK_PREFIX.libao=libao
BUILDLINK_PREFIX.libao=	${LOCALBASE}
BUILDLINK_FILES.libao=	include/ao/ao.h
BUILDLINK_FILES.libao+=	include/ao/os_types.h
BUILDLINK_FILES.libao+=	lib/libao.*
BUILDLINK_FILES.libao+=	lib/ao/*

.include "../../devel/pkgconfig/buildlink2.mk"

BUILDLINK_TARGETS+=	libao-buildlink

libao-buildlink: _BUILDLINK_USE

.endif	# LIBAO_BUILDLINK2_MK
