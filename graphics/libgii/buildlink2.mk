# $NetBSD: buildlink2.mk,v 1.1 2002/11/25 20:33:36 jlam Exp $

.if !defined(LIBGII_BUILDLINK2_MK)
LIBGII_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libgii
BUILDLINK_DEPENDS.libgii?=	libgii>=0.6
BUILDLINK_PKGSRCDIR.libgii?=	../../graphics/libgii

EVAL_PREFIX+=	BUILDLINK_PREFIX.libgii=libgii
BUILDLINK_PREFIX.libgii_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libgii+=	include/ggi/errors.h
BUILDLINK_FILES.libgii+=	include/ggi/events.h
BUILDLINK_FILES.libgii+=	include/ggi/gg.h
BUILDLINK_FILES.libgii+=	include/ggi/gii-unix.h
BUILDLINK_FILES.libgii+=	include/ggi/gii.h
BUILDLINK_FILES.libgii+=	include/ggi/input/lin_kbd.h
BUILDLINK_FILES.libgii+=	include/ggi/input/xwin.h
BUILDLINK_FILES.libgii+=	include/ggi/internal/gii-dl.h
BUILDLINK_FILES.libgii+=	include/ggi/internal/gii.h
BUILDLINK_FILES.libgii+=	include/ggi/internal/gii_debug.h
BUILDLINK_FILES.libgii+=	include/ggi/keyboard.h
BUILDLINK_FILES.libgii+=	include/ggi/system.h
BUILDLINK_FILES.libgii+=	lib/libgg.*
BUILDLINK_FILES.libgii+=	lib/libgii.*

BUILDLINK_TARGETS+=	libgii-buildlink

libgii-buildlink: _BUILDLINK_USE

.endif	# LIBGII_BUILDLINK2_MK
