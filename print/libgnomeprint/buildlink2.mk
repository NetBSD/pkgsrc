# $NetBSD: buildlink2.mk,v 1.10 2003/11/12 01:31:51 salo Exp $
#
# This Makefile fragment is included by packages that use libgnomeprint.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(LIBGNOMEPRINT_BUILDLINK2_MK)
LIBGNOMEPRINT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libgnomeprint
BUILDLINK_DEPENDS.libgnomeprint?=	libgnomeprint>=2.2.1.2nb3
BUILDLINK_PKGSRCDIR.libgnomeprint?=	../../print/libgnomeprint

EVAL_PREFIX+=	BUILDLINK_PREFIX.libgnomeprint=libgnomeprint
BUILDLINK_PREFIX.libgnomeprint_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libgnomeprint+=	include/libgnomeprint-2.2/libgnomeprint/*
BUILDLINK_FILES.libgnomeprint+=	include/libgnomeprint-2.2/libgnomeprint/private/*
BUILDLINK_FILES.libgnomeprint+=	lib/libgnomeprint-2-2.*
BUILDLINK_FILES.libgnomeprint+=	lib/libgnomeprint/2.2.1.1/modules/transports/libgnomeprint-custom.*
BUILDLINK_FILES.libgnomeprint+=	lib/libgnomeprint/2.2.1.1/modules/transports/libgnomeprint-file.*
BUILDLINK_FILES.libgnomeprint+=	lib/libgnomeprint/2.2.1.1/modules/transports/libgnomeprint-lpr.*
BUILDLINK_FILES.libgnomeprint+=	lib/pkgconfig/libgnomeprint-2.2.pc

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libbonobo/buildlink2.mk"
.include "../../devel/pango/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/libart2/buildlink2.mk"

BUILDLINK_TARGETS+=	libgnomeprint-buildlink

libgnomeprint-buildlink: _BUILDLINK_USE

.endif	# LIBGNOMEPRINT_BUILDLINK2_MK
