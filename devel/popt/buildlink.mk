# $NetBSD: buildlink.mk,v 1.2 2002/01/13 11:45:31 wiz Exp $
#
# This Makefile fragment is included by packages that use popt.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.popt to the dependency pattern
#     for the version of popt desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(POPT_BUILDLINK_MK)
POPT_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.popt?=	popt>=1.6.2
DEPENDS+=	${BUILDLINK_DEPENDS.popt}:../../devel/popt

EVAL_PREFIX+=			BUILDLINK_PREFIX.popt=popt
BUILDLINK_PREFIX.popt_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.popt=		include/popt.h
BUILDLINK_FILES.popt+=		lib/libpopt.*

.include "../../devel/gettext-lib/buildlink.mk"

BUILDLINK_TARGETS.popt=		popt-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.popt}

pre-configure: ${BUILDLINK_TARGETS.popt}
popt-buildlink: _BUILDLINK_USE

.endif	# POPT_BUILDLINK_MK
