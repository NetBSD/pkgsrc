# $NetBSD: buildlink2.mk,v 1.6 2003/12/03 01:32:08 reed Exp $

.if !defined(IMLIB_BUILDLINK2_MK)
IMLIB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		imlib
BUILDLINK_DEPENDS.imlib?=	imlib>=1.9.14nb4
BUILDLINK_PKGSRCDIR.imlib?=	../../graphics/imlib

EVAL_PREFIX+=		BUILDLINK_PREFIX.imlib=imlib
BUILDLINK_PREFIX.imlib_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.imlib=	bin/imlib-config
BUILDLINK_FILES.imlib+=	include/gdk_imlib.h
BUILDLINK_FILES.imlib+=	include/gdk_imlib_private.h
BUILDLINK_FILES.imlib+=	include/gdk_imlib_types.h
BUILDLINK_FILES.imlib+=	include/Imlib.h
BUILDLINK_FILES.imlib+=	include/Imlib_private.h
BUILDLINK_FILES.imlib+=	include/Imlib_types.h
BUILDLINK_FILES.imlib+=	lib/libImlib.*
BUILDLINK_FILES.imlib+=	lib/libgdk_imlib.*

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/libungif/buildlink2.mk"
.include "../../graphics/netpbm/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

BUILDLINK_TARGETS+=	imlib-buildlink

imlib-buildlink: _BUILDLINK_USE

.endif	# IMLIB_BUILDLINK2_MK
