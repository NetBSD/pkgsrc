# $NetBSD: buildlink2.mk,v 1.5 2004/02/16 00:12:52 jmmv Exp $
#
# This Makefile fragment is included by packages that use gucharmap.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(GUCHARMAP_BUILDLINK2_MK)
GUCHARMAP_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gucharmap
BUILDLINK_DEPENDS.gucharmap?=		gucharmap>=1.2.0nb2
BUILDLINK_PKGSRCDIR.gucharmap?=		../../fonts/gucharmap

EVAL_PREFIX+=	BUILDLINK_PREFIX.gucharmap=gucharmap
BUILDLINK_PREFIX.gucharmap_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gucharmap+=	include/gucharmap/*
BUILDLINK_FILES.gucharmap+=	lib/libgucharmap.*

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libgnome/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/pango/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

BUILDLINK_TARGETS+=	gucharmap-buildlink

gucharmap-buildlink: _BUILDLINK_USE

.endif	# GUCHARMAP_BUILDLINK2_MK
