# $NetBSD: buildlink2.mk,v 1.1 2003/07/02 10:24:12 wulf Exp $

.if !defined(HAMLIB_BUILDLINK2_MK)
HAMLIB_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_PACKAGES+=		hamlib
BUILDLINK_PKGBASE.hamlib=	hamlib
BUILDLINK_DEPENDS.hamlib?=	hamlib>=1.1.4
BUILDLINK_PKGSRCDIR.hamlib?=	../../ham/hamlib

EVAL_PREFIX+=			BUILDLINK_PREFIX.hamlib=hamlib
BUILDLINK_PREFIX.hamblib_DEFAULT= ${LOCALBASE}
BUILDLINK_FILES.hamlib+=	include/hamlib/*.h
BUILDLINK_FILES.hamlib+=	lib/libhamlib.*

BUILDLINK_TARGETS+=		hamlib-buildlink

hamlib-buildlink: _BUILDLINK_USE

.endif	# HAMLIB_BUILDLINK2_MK
