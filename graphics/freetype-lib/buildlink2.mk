# $NetBSD: buildlink2.mk,v 1.4 2004/03/29 05:05:39 jlam Exp $

.if !defined(FREETYPE_BUILDLINK2_MK)
FREETYPE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		freetype
BUILDLINK_PKGBASE.freetype?=	freetype-lib
BUILDLINK_DEPENDS.freetype?=	freetype-lib>=1.3.1nb1
BUILDLINK_PKGSRCDIR.freetype?=	../../graphics/freetype-lib

EVAL_PREFIX+=	BUILDLINK_PREFIX.freetype=freetype-lib
BUILDLINK_PREFIX.freetype_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.freetype=	include/freetype/*
BUILDLINK_FILES.freetype+=	lib/libttf.*

.include "../../devel/gettext-lib/buildlink2.mk"

BUILDLINK_TARGETS+=	freetype-buildlink

freetype-buildlink: _BUILDLINK_USE

.endif	# FREETYPE_BUILDLINK2_MK
