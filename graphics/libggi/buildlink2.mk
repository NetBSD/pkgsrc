# $NetBSD: buildlink2.mk,v 1.1 2002/11/25 20:50:26 jlam Exp $

.if !defined(LIBGGI_BUILDLINK2_MK)
LIBGGI_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libggi
BUILDLINK_DEPENDS.libggi?=	libggi>=2.0b2.1
BUILDLINK_PKGSRCDIR.libggi?=	../../graphics/libggi

EVAL_PREFIX+=	BUILDLINK_PREFIX.libggi=libggi
BUILDLINK_PREFIX.libggi_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libggi+=	include/ggi/display/aa.h
BUILDLINK_FILES.libggi+=	include/ggi/display/fbdev.h
BUILDLINK_FILES.libggi+=	include/ggi/display/file.h
BUILDLINK_FILES.libggi+=	include/ggi/display/glide.h
BUILDLINK_FILES.libggi+=	include/ggi/display/linvtsw.h
BUILDLINK_FILES.libggi+=	include/ggi/display/mansync.h
BUILDLINK_FILES.libggi+=	include/ggi/display/memory.h
BUILDLINK_FILES.libggi+=	include/ggi/display/modelist.h
BUILDLINK_FILES.libggi+=	include/ggi/display/monotext.h
BUILDLINK_FILES.libggi+=	include/ggi/display/multi.h
BUILDLINK_FILES.libggi+=	include/ggi/display/palemu.h
BUILDLINK_FILES.libggi+=	include/ggi/display/sub.h
BUILDLINK_FILES.libggi+=	include/ggi/display/svgalib.h
BUILDLINK_FILES.libggi+=	include/ggi/display/tele.h
BUILDLINK_FILES.libggi+=	include/ggi/display/tile.h
BUILDLINK_FILES.libggi+=	include/ggi/display/trueemu.h
BUILDLINK_FILES.libggi+=	include/ggi/display/vcsa.h
BUILDLINK_FILES.libggi+=	include/ggi/display/x.h
BUILDLINK_FILES.libggi+=	include/ggi/display/xcommon.h
BUILDLINK_FILES.libggi+=	include/ggi/display/xf86dga.h
BUILDLINK_FILES.libggi+=	include/ggi/display/xlib.h
BUILDLINK_FILES.libggi+=	include/ggi/ggi-unix.h
BUILDLINK_FILES.libggi+=	include/ggi/ggi.h
BUILDLINK_FILES.libggi+=	include/ggi/ggi_ext.h
BUILDLINK_FILES.libggi+=	include/ggi/internal/debug.h
BUILDLINK_FILES.libggi+=	include/ggi/internal/dltypes.h
BUILDLINK_FILES.libggi+=	include/ggi/internal/ggi-dl.h
BUILDLINK_FILES.libggi+=	include/ggi/internal/ggidlinit.h
BUILDLINK_FILES.libggi+=	include/ggi/internal/ggilibinit.h
BUILDLINK_FILES.libggi+=	include/ggi/internal/internal.h
BUILDLINK_FILES.libggi+=	include/ggi/internal/misc_int.h
BUILDLINK_FILES.libggi+=	include/ggi/internal/plat.h
BUILDLINK_FILES.libggi+=	include/ggi/internal/structs.h
BUILDLINK_FILES.libggi+=	include/ggi/misc.h
BUILDLINK_FILES.libggi+=	include/ggi/types.h
BUILDLINK_FILES.libggi+=	lib/libggi.*
BUILDLINK_FILES.libggi+=	lib/libggimisc.*

USE_X11=		# defined

.include "../../graphics/libgii/buildlink2.mk"

BUILDLINK_TARGETS+=	libggi-buildlink

libggi-buildlink: _BUILDLINK_USE

.endif	# LIBGGI_BUILDLINK2_MK
