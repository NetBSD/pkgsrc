# $NetBSD: buildlink2.mk,v 1.2 2003/06/07 17:39:24 jschauma Exp $

.if !defined(PLOTUTILS_BUILDLINK2_MK)
PLOTUTILS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		plotutils
BUILDLINK_DEPENDS.plotutils?=	plotutils>=2.4.1nb2
BUILDLINK_PKGSRCDIR.plotutils?=	../../graphics/plotutils

EVAL_PREFIX+=	BUILDLINK_PREFIX.plotutils=plotutils
BUILDLINK_PREFIX.plotutils_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.plotutils+=	include/plot.h
BUILDLINK_FILES.plotutils+=	include/plotcompat.h
BUILDLINK_FILES.plotutils+=	include/plotter.h
BUILDLINK_FILES.plotutils+=	lib/libplot.*
BUILDLINK_FILES.plotutils+=	lib/libplotter.*

.include "../../graphics/png/buildlink2.mk"

BUILDLINK_TARGETS+=	plotutils-buildlink

plotutils-buildlink: _BUILDLINK_USE

.endif	# PLOTUTILS_BUILDLINK2_MK
