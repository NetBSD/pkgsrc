# $NetBSD: buildlink2.mk,v 1.3 2003/04/02 12:03:42 wiz Exp $

.if !defined(LIBGII_BUILDLINK2_MK)
LIBGII_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libgii
BUILDLINK_DEPENDS.libgii?=	libgii>=0.8.3
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
BUILDLINK_FILES.libgii+=	include/ggi/keyboard.h
BUILDLINK_FILES.libgii+=	include/ggi/system.h
BUILDLINK_FILES.libgii+=	lib/libgg.*
BUILDLINK_FILES.libgii+=	lib/libgii.*

USE_X11=		# defined

BUILDLINK_TARGETS+=	libgii-buildlink

libgii-buildlink: _BUILDLINK_USE

.endif	# LIBGII_BUILDLINK2_MK
