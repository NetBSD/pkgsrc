# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/06 06:54:40 jlam Exp $
#
# This Makefile fragment is included by packages that use imlib.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.imlib to the dependency pattern
#     for the version of imlib desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(IMLIB_BUILDLINK2_MK)
IMLIB_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.imlib?=	imlib>=1.9.11nb1
DEPENDS+=	${BUILDLINK_DEPENDS.imlib}:../../graphics/imlib

EVAL_PREFIX+=		BUILDLINK_PREFIX.imlib=imlib
BUILDLINK_PREFIX.imlib_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.imlib=	include/gdk_imlib.h
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
