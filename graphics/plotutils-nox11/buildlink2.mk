# $NetBSD: buildlink2.mk,v 1.1 2003/06/07 17:39:24 jschauma Exp $

.if !defined(PLOTUTILS_BUILDLINK2_MK)
PLOTUTILS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		plotutils-nox11
BUILDLINK_DEPENDS.plotutils-nox11?=	plotutils-nox11>=2.4.1
BUILDLINK_PKGSRCDIR.plotutils-nox11?=	../../graphics/plotutils-nox11

EVAL_PREFIX+=	BUILDLINK_PREFIX.plotutils=plotutils
BUILDLINK_PREFIX.plotutils-nox11_DEFAULT=	${PREFIX}
BUILDLINK_FILES.plotutils-nox11+=	include/plot.h
BUILDLINK_FILES.plotutils-nox11+=	include/plotcompat.h
BUILDLINK_FILES.plotutils-nox11+=	include/plotter.h
BUILDLINK_FILES.plotutils-nox11+=	lib/libplot.*
BUILDLINK_FILES.plotutils-nox11+=	lib/libplotter.*

.include "../../graphics/png/buildlink2.mk"

BUILDLINK_TARGETS+=	plotutils-nox11-buildlink

plotutils-nox11-buildlink: _BUILDLINK_USE

.endif	# PLOTUTILS_BUILDLINK2_MK
