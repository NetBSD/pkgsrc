# $NetBSD: buildlink.mk,v 1.1 2001/11/30 05:45:17 jlam Exp $
#
# This Makefile fragment is included by packages that use cim.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.cim to the dependency pattern
#     for the version of cim desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(CIM_BUILDLINK_MK)
CIM_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.cim?=	cim>=3.30
DEPENDS+=	${BUILDLINK_DEPENDS.cim}:../../lang/cim

EVAL_PREFIX+=			BUILDLINK_PREFIX.cim=cim
BUILDLINK_PREFIX.cim_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.cim=		include/cim.h
BUILDLINK_FILES.cim+=		lib/libcim-atr.*
BUILDLINK_FILES.cim+=		lib/libcim.*

BUILDLINK_TARGETS.cim=	cim-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.cim}

pre-configure: ${BUILDLINK_TARGETS.cim}
cim-buildlink: _BUILDLINK_USE

.endif	# CIM_BUILDLINK_MK
