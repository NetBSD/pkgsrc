# $NetBSD: buildlink2.mk,v 1.3 2003/07/13 13:51:25 wiz Exp $

.if !defined(POPT_BUILDLINK2_MK)
POPT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		popt
BUILDLINK_DEPENDS.popt?=	popt>=1.7nb2
BUILDLINK_PKGSRCDIR.popt?=	../../devel/popt

EVAL_PREFIX+=			BUILDLINK_PREFIX.popt=popt
BUILDLINK_PREFIX.popt_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.popt=		include/popt.h
BUILDLINK_FILES.popt+=		lib/libpopt.*

.include "../../devel/gettext-lib/buildlink2.mk"

BUILDLINK_TARGETS+=		popt-buildlink

popt-buildlink: _BUILDLINK_USE

.endif	# POPT_BUILDLINK2_MK
