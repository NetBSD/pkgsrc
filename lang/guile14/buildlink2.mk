# $NetBSD: buildlink2.mk,v 1.3 2003/01/07 03:56:26 uebayasi Exp $

.if !defined(GUILE14_BUILDLINK2_MK)
GUILE14_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		guile14
BUILDLINK_DEPENDS.guile14?=	guile14>=1.4
BUILDLINK_PKGSRCDIR.guile14?=	../../lang/guile14

EVAL_PREFIX+=				BUILDLINK_PREFIX.guile14=guile14
BUILDLINK_PREFIX.guile14_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.guile14+=		include/guile/*
BUILDLINK_FILES.guile14+=		include/guile-readline/*
BUILDLINK_FILES.guile14+=		include/libguile.h
BUILDLINK_FILES.guile14+=		include/libguile/*
BUILDLINK_FILES.guile14+=		lib/libguile.*
BUILDLINK_FILES.guile14+=		lib/libguilereadline.*

USE_GNU_READLINE=	# defined

.include "../../devel/libtool/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"

BUILDLINK_TARGETS+=	guile14-buildlink

guile14-buildlink: _BUILDLINK_USE

.endif	# GUILE14_BUILDLINK2_MK
