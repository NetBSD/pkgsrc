# $NetBSD: buildlink.mk,v 1.2 2001/06/23 19:26:50 jlam Exp $
#
# This Makefile fragment is included by packages that use freetds.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.freetds to the dependency pattern
#     for the version of freetds desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(FREETDS_BUILDLINK_MK)
FREETDS_BUILDLINK_MK=	# defined

BUILDLINK_DEPENDS.freetds?=	freetds>=0.50
DEPENDS+=	${BUILDLINK_DEPENDS.freetds}:../../databases/freetds

BUILDLINK_PREFIX.freetds=	${LOCALBASE}
BUILDLINK_FILES.freetds=	freetds/include/*
BUILDLINK_FILES.freetds+=	freetds/lib/*
BUILDLINK_FILES.freetds+=	freetds/interfaces

BUILDLINK_TARGETS.freetds=	freetds-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.freetds}

pre-configure: ${BUILDLINK_TARGETS.freetds}
freetds-buildlink: _BUILDLINK_USE

.include "../../mk/bsd.buildlink.mk"

.endif	# FREETDS_BUILDLINK_MK
