# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/06 06:54:39 jlam Exp $
#
# This Makefile fragment is included by packages that use freetype.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.freetype to the dependency pattern
#     for the version of freetype desired.
# (2) Include this Makefile fragment in the package Makefile.

.if !defined(FREETYPE_BUILDLINK2_MK)
FREETYPE_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.buildlink2.mk"

BUILDLINK_DEPENDS.freetype?=	freetype-lib>=1.3.1
DEPENDS+=	${BUILDLINK_DEPENDS.freetype}:../../graphics/freetype-lib

EVAL_PREFIX+=	BUILDLINK_PREFIX.freetype=freetype-lib
BUILDLINK_PREFIX.freetype_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.freetype=	include/freetype/*
BUILDLINK_FILES.freetype+=	lib/libttf.*

.include "../../devel/gettext-lib/buildlink2.mk"

BUILDLINK_TARGETS+=	freetype-buildlink

freetype-buildlink: _BUILDLINK_USE

.endif	# FREETYPE_BUILDLINK2_MK
