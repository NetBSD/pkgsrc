# $NetBSD: buildlink.mk,v 1.1.2.2 2002/06/23 18:51:07 jlam Exp $
#
# This Makefile fragment is included by packages that use drac.
#
# This file was created automatically using createbuildlink 1.5.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.drac to the dependency pattern
#     for the version of drac desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(DRAC_BUILDLINK_MK)
DRAC_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.drac?=		drac>=1.10
DEPENDS+=	${BUILDLINK_DEPENDS.drac}:../../mail/drac

EVAL_PREFIX+=	BUILDLINK_PREFIX.drac=drac
BUILDLINK_PREFIX.drac_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.drac+=	include/drac.h
BUILDLINK_FILES.drac+=	lib/libdrac.*


BUILDLINK_TARGETS.drac=	drac-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.drac}

pre-configure: ${BUILDLINK_TARGETS}
drac-buildlink: _BUILDLINK_USE

.endif	# DRAC_BUILDLINK_MK
