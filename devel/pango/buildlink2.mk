# $NetBSD: buildlink2.mk,v 1.8 2004/04/01 18:15:16 jmmv Exp $

.if !defined(PANGO_BUILDLINK2_MK)
PANGO_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		pango
BUILDLINK_DEPENDS.pango?=	pango>=1.4.0
BUILDLINK_PKGSRCDIR.pango?=	../../devel/pango

EVAL_PREFIX+=		BUILDLINK_PREFIX.pango=pango
BUILDLINK_PREFIX.pango_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.pango=	include/pango-1.0/*/*
BUILDLINK_FILES.pango+=	include/pango-1.0/*
BUILDLINK_FILES.pango+=	lib/libpango*-1.0.*

.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../fonts/fontconfig/buildlink2.mk"
.include "../../fonts/Xft2/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../x11/Xrender/buildlink2.mk"

BUILDLINK_TARGETS+=	pango-buildlink

pango-buildlink: _BUILDLINK_USE

.endif	# PANGO_BUILDLINK2_MK
