# $NetBSD: buildlink2.mk,v 1.8 2003/07/13 13:52:21 wiz Exp $

.if !defined(GUILE_BUILDLINK2_MK)
GUILE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		guile
BUILDLINK_DEPENDS.guile?=	guile>=1.6.3nb1
BUILDLINK_PKGSRCDIR.guile?=	../../lang/guile

EVAL_PREFIX+=		BUILDLINK_PREFIX.guile=guile
BUILDLINK_PREFIX.guile_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.guile+=	include/guile/*
BUILDLINK_FILES.guile+=	include/guile/srfi/*
BUILDLINK_FILES.guile+=	include/guile-readline/*
BUILDLINK_FILES.guile+=	include/libguile.h
BUILDLINK_FILES.guile+=	include/libguile/*
BUILDLINK_FILES.guile+=	lib/libguile.*
BUILDLINK_FILES.guile+=	lib/libguile-*
BUILDLINK_FILES.guile+=	lib/libguilereadline-*

USE_GNU_READLINE=	# defined

.include "../../devel/libtool/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"

BUILDLINK_TARGETS+=	guile-buildlink

guile-buildlink: _BUILDLINK_USE

.endif	# GUILE_BUILDLINK2_MK
