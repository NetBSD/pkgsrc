# $NetBSD: buildlink2.mk,v 1.3 2003/07/13 13:53:33 wiz Exp $

.if !defined(JADE_BUILDLINK2_MK)
JADE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		jade
BUILDLINK_DEPENDS.jade?=	jade>=1.2.1nb7
BUILDLINK_PKGSRCDIR.jade?=	../../textproc/jade

EVAL_PREFIX+=		BUILDLINK_PREFIX.jade=jade
BUILDLINK_PREFIX.jade_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.jade=	include/sp/*
BUILDLINK_FILES.jade+=	lib/libgrove.*
BUILDLINK_FILES.jade+=	lib/libsp.*
BUILDLINK_FILES.jade+=	lib/libspgrove.*
BUILDLINK_FILES.jade+=	lib/libstyle.*

.include "../../devel/gettext-lib/buildlink2.mk"

BUILDLINK_TARGETS+=	jade-buildlink

jade-buildlink: _BUILDLINK_USE

.endif	# JADE_BUILDLINK2_MK
