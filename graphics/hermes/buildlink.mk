# $NetBSD: buildlink.mk,v 1.4 2001/07/27 13:33:28 jlam Exp $
#
# This Makefile fragment is included by packages that use Hermes.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.Hermes to the dependency pattern
#     for the version of Hermes desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(HERMES_BUILDLINK_MK)
HERMES_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.Hermes?=	Hermes>=1.3.2
DEPENDS+=	${BUILDLINK_DEPENDS.Hermes}:../../graphics/hermes

EVAL_PREFIX+=			BUILDLINK_PREFIX.Hermes=Hermes
BUILDLINK_PREFIX.Hermes_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.Hermes=		include/Hermes/*
BUILDLINK_FILES.Hermes+=	lib/libHermes.*

BUILDLINK_TARGETS.Hermes=	Hermes-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.Hermes}

pre-configure: ${BUILDLINK_TARGETS.Hermes}
Hermes-buildlink: _BUILDLINK_USE

.endif	# HERMES_BUILDLINK_MK
