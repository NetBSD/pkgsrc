# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:17 jlam Exp $

.if !defined(POPT_BUILDLINK2_MK)
POPT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		popt
BUILDLINK_DEPENDS.popt?=	popt>=1.6.2
BUILDLINK_PKGSRCDIR.popt?=	../../devel/popt

EVAL_PREFIX+=			BUILDLINK_PREFIX.popt=popt
BUILDLINK_PREFIX.popt_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.popt=		include/popt.h
BUILDLINK_FILES.popt+=		lib/libpopt.*

.include "../../devel/gettext-lib/buildlink2.mk"

BUILDLINK_TARGETS+=		popt-buildlink

popt-buildlink: _BUILDLINK_USE

.endif	# POPT_BUILDLINK2_MK
