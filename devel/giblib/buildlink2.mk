# $NetBSD: buildlink2.mk,v 1.1.1.1 2002/09/20 10:55:40 rh Exp $
#
# This Makefile fragment is included by packages that use giblib.
#
# This file was created automatically using createbuildlink 2.0.
#

.if !defined(GIBLIB_BUILDLINK2_MK)
GIBLIB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			giblib
BUILDLINK_DEPENDS.giblib?=		giblib>=1.2.2
BUILDLINK_PKGSRCDIR.giblib?=		../../devel/giblib

EVAL_PREFIX+=	BUILDLINK_PREFIX.giblib=giblib
BUILDLINK_PREFIX.giblib_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.giblib+=	include/giblib/gib_btree.h
BUILDLINK_FILES.giblib+=	include/giblib/gib_hash.h
BUILDLINK_FILES.giblib+=	include/giblib/gib_imlib.h
BUILDLINK_FILES.giblib+=	include/giblib/gib_list.h
BUILDLINK_FILES.giblib+=	include/giblib/gib_queue.h
BUILDLINK_FILES.giblib+=	include/giblib/gib_stack.h
BUILDLINK_FILES.giblib+=	include/giblib/gib_style.h
BUILDLINK_FILES.giblib+=	include/giblib/gib_utils.h
BUILDLINK_FILES.giblib+=	include/giblib/giblib.h
BUILDLINK_FILES.giblib+=	include/giblib/giblib_config.h
BUILDLINK_FILES.giblib+=	lib/libgiblib.*

.include "../../graphics/imlib2/buildlink2.mk"

BUILDLINK_TARGETS+=	giblib-buildlink

giblib-buildlink: _BUILDLINK_USE

.endif	# GIBLIB_BUILDLINK2_MK
