# $NetBSD: buildlink2.mk,v 1.1.1.1 2004/02/09 00:30:24 chris Exp $
#
# This Makefile fragment is included by packages that use taglib.
#
# This file was created automatically using createbuildlink-3.0.
#

.if !defined(TAGLIB_BUILDLINK2_MK)
TAGLIB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			taglib
BUILDLINK_DEPENDS.taglib?=		taglib>=1.0
BUILDLINK_PKGSRCDIR.taglib?=		../../audio/TagLib

EVAL_PREFIX+=	BUILDLINK_PREFIX.taglib=taglib
BUILDLINK_PREFIX.taglib_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.taglib+=	include/taglib/*.h
BUILDLINK_FILES.taglib+=	include/taglib/*.tcc
BUILDLINK_FILES.taglib+=	lib/libtag.*
BUILDLINK_FILES.taglib+=	lib/libtag_c.*

BUILDLINK_TARGETS+=	taglib-buildlink

taglib-buildlink: _BUILDLINK_USE

.endif	# TAGLIB_BUILDLINK2_MK
