# $NetBSD: buildlink2.mk,v 1.3 2003/07/13 13:52:10 wiz Exp $

.if !defined(LIBGGI_BUILDLINK2_MK)
LIBGGI_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libggi
BUILDLINK_DEPENDS.libggi?=	libggi>=2.0.3nb1
BUILDLINK_PKGSRCDIR.libggi?=	../../graphics/libggi

EVAL_PREFIX+=	BUILDLINK_PREFIX.libggi=libggi
BUILDLINK_PREFIX.libggi_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libggi+=	include/ggi/display/*
BUILDLINK_FILES.libggi+=	include/ggi/ggi-unix.h
BUILDLINK_FILES.libggi+=	include/ggi/ggi.h
BUILDLINK_FILES.libggi+=	include/ggi/ggi_ext.h
BUILDLINK_FILES.libggi+=	include/ggi/internal/debug.h
BUILDLINK_FILES.libggi+=	include/ggi/internal/dltypes.h
BUILDLINK_FILES.libggi+=	include/ggi/internal/ggi-dl.h
BUILDLINK_FILES.libggi+=	include/ggi/internal/ggidlinit.h
BUILDLINK_FILES.libggi+=	include/ggi/internal/ggilibinit.h
BUILDLINK_FILES.libggi+=	include/ggi/internal/internal.h
BUILDLINK_FILES.libggi+=	include/ggi/internal/plat.h
BUILDLINK_FILES.libggi+=	include/ggi/internal/structs.h
BUILDLINK_FILES.libggi+=	include/ggi/ll.h
BUILDLINK_FILES.libggi+=	include/ggi/types.h
BUILDLINK_FILES.libggi+=	lib/libggi.*

USE_X11=		# defined

.include "../../graphics/libgii/buildlink2.mk"

BUILDLINK_TARGETS+=	libggi-buildlink

libggi-buildlink: _BUILDLINK_USE

.endif	# LIBGGI_BUILDLINK2_MK
