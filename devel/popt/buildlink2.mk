# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:22:37 jlam Exp $

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
