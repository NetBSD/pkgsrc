# $NetBSD: buildlink2.mk,v 1.1 2003/07/10 08:55:04 jtb Exp $
#
# This Makefile fragment is included by packages that use plplot.
#

.if !defined(PLPLOT_BUILDLINK2_MK)
PLPLOT_BUILDLINK2_MK=		# defined

BUILDLINK_PACKAGES+=		plplot
BUILDLINK_DEPENDS.plplot?=	plplot>=5.2.1
BUILDLINK_PKGSRCDIR.plplot?=	../../graphics/plplot

EVAL_PREFIX+=			BUILDLINK_PREFIX.plplot=plplot
BUILDLINK_PREFIX.plplot_DEFAULT=${LOCALBASE}
BUILDLINK_FILES.plplot+=	include/plplot/*
BUILDLINK_FILES.plplot+=	lib/libplplot.*

BUILDLINK_TARGETS+=		plplot-buildlink

plplot-buildlink: _BUILDLINK_USE

.endif	# PLPLOT_BUILDLINK2_MK
