# $NetBSD: buildlink2.mk,v 1.9 2003/09/19 17:23:17 wiz Exp $
#
# This Makefile fragment is included by packages that use Xft2.
#
# This file was created automatically using createbuildlink 2.2.
#

.if !defined(XFT2_BUILDLINK2_MK)
XFT2_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			Xft2
BUILDLINK_DEPENDS.Xft2?=		Xft2>=2.1nb1
BUILDLINK_PKGSRCDIR.Xft2?=		../../fonts/Xft2

EVAL_PREFIX+=	BUILDLINK_PREFIX.Xft2=Xft2
BUILDLINK_PREFIX.Xft2_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.Xft2+=	include/X11/Xft/*
BUILDLINK_FILES.Xft2+=	lib/libXft.*
BUILDLINK_FILES.Xft2+=	lib/pkgconfig/xft.pc

BUILDLINK_DEPENDS.Xrender=	Xrender>=0.8.2

.include "../../fonts/fontconfig/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../x11/Xrender/buildlink2.mk"

BUILDLINK_TARGETS+=	Xft2-buildlink

Xft2-buildlink: _BUILDLINK_USE

.endif	# XFT2_BUILDLINK2_MK
