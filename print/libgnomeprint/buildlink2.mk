# $NetBSD: buildlink2.mk,v 1.12 2003/12/14 22:35:35 jmmv Exp $
#
# This Makefile fragment is included by packages that use libgnomeprint.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(LIBGNOMEPRINT_BUILDLINK2_MK)
LIBGNOMEPRINT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libgnomeprint
BUILDLINK_DEPENDS.libgnomeprint?=		libgnomeprint>=2.4.0
BUILDLINK_PKGSRCDIR.libgnomeprint?=		../../print/libgnomeprint

EVAL_PREFIX+=	BUILDLINK_PREFIX.libgnomeprint=libgnomeprint
BUILDLINK_PREFIX.libgnomeprint_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libgnomeprint+=	include/libgnomeprint-2.2/libgnomeprint/*
BUILDLINK_FILES.libgnomeprint+=	include/libgnomeprint-2.2/libgnomeprint/private/*
BUILDLINK_FILES.libgnomeprint+=	lib/libgnomeprint-2-2.*
BUILDLINK_FILES.libgnomeprint+=	lib/libgnomeprint/${PKGVERSION}/modules/transports/libgnomeprint-custom.*
BUILDLINK_FILES.libgnomeprint+=	lib/libgnomeprint/${PKGVERSION}/modules/transports/libgnomeprint-file.*
BUILDLINK_FILES.libgnomeprint+=	lib/libgnomeprint/${PKGVERSION}/modules/transports/libgnomeprint-lpr.*

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/libbonobo/buildlink2.mk"
.include "../../devel/pango/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/libart2/buildlink2.mk"

.include "../../mk/bsd.prefs.mk"

.if defined(USE_CUPS) && !empty(USE_CUPS:M[Yy][Ee][Ss])
.include "../../print/cups/buildlink2.mk"
.endif

BUILDLINK_TARGETS+=	libgnomeprint-buildlink

libgnomeprint-buildlink: _BUILDLINK_USE

.endif	# LIBGNOMEPRINT_BUILDLINK2_MK
