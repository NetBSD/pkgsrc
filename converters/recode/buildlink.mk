# $NetBSD: buildlink.mk,v 1.1 2001/08/20 03:34:29 jlam Exp $
#
# This Makefile fragment is included by packages that use recode.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.recode to the dependency pattern
#     for the version of recode desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(RECODE_BUILDLINK_MK)
RECODE_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.recode?=	recode>=3.5
DEPENDS+=	${BUILDLINK_DEPENDS.recode}:../../databases/recode

EVAL_PREFIX+=			BUILDLINK_PREFIX.recode=recode
BUILDLINK_PREFIX.recode_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.recode=		include/recode.h
BUILDLINK_FILES.recode+=	include/recodext.h
BUILDLINK_FILES.recode+=	lib/librecode.*

.include "../../devel/gettext-lib/buildlink.mk"

BUILDLINK_TARGETS.recode=	recode-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.recode}

pre-configure: ${BUILDLINK_TARGETS.recode}
recode-buildlink: _BUILDLINK_USE

.endif	# RECODE_BUILDLINK_MK
