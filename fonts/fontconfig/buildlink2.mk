# $NetBSD: buildlink2.mk,v 1.1.1.1 2002/12/11 20:12:45 jmmv Exp $
#
# This Makefile fragment is included by packages that use fontconfig.
#
# This file was created automatically using createbuildlink 2.2.
#

.if !defined(FONTCONFIG_BUILDLINK2_MK)
FONTCONFIG_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			fontconfig
BUILDLINK_DEPENDS.fontconfig?=		fontconfig>=2.1
BUILDLINK_PKGSRCDIR.fontconfig?=		../../fonts/fontconfig

EVAL_PREFIX+=	BUILDLINK_PREFIX.fontconfig=fontconfig
BUILDLINK_PREFIX.fontconfig_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.fontconfig+=	include/fontconfig/fcfreetype.h
BUILDLINK_FILES.fontconfig+=	include/fontconfig/fcprivate.h
BUILDLINK_FILES.fontconfig+=	include/fontconfig/fontconfig.h
BUILDLINK_FILES.fontconfig+=	lib/libfontconfig.*
BUILDLINK_FILES.fontconfig+=	lib/pkgconfig/fontconfig.pc

.include "../../graphics/freetype2/buildlink2.mk"
.include "../../textproc/expat/buildlink2.mk"

BUILDLINK_TARGETS+=	fontconfig-buildlink

fontconfig-buildlink: _BUILDLINK_USE

.endif	# FONTCONFIG_BUILDLINK2_MK
