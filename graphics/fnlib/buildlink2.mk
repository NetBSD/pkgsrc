# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:23 jlam Exp $

.if !defined(FNLIB_BUILDLINK2_MK)
FNLIB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		fnlib
BUILDLINK_DEPENDS.fnlib?=	fnlib>=0.5nb1
BUILDLINK_PKGSRCDIR.fnlib?=	../../graphics/fnlib

EVAL_PREFIX+=		BUILDLINK_PREFIX.fnlib=fnlib
BUILDLINK_PREFIX.fnlib_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.fnlib=	include/Fnlib*
BUILDLINK_FILES.fnlib+=	lib/libFnlib.*

.include "../../graphics/imlib/buildlink2.mk"

BUILDLINK_TARGETS+=	fnlib-buildlink

fnlib-buildlink: _BUILDLINK_USE

.endif	# FNLIB_BUILDLINK2_MK
