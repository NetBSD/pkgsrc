# $NetBSD: buildlink.mk,v 1.11 2002/09/20 00:15:56 grant Exp $
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

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.freetds?=	freetds>=0.53nb1
DEPENDS+=	${BUILDLINK_DEPENDS.freetds}:../../databases/freetds

EVAL_PREFIX+=			BUILDLINK_PREFIX.freetds=freetds
BUILDLINK_PREFIX.freetds_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.freetds=	freetds/include/*
BUILDLINK_FILES.freetds+=	freetds/lib/*

BUILDLINK_TARGETS.freetds=	freetds-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.freetds}

pre-configure: ${BUILDLINK_TARGETS.freetds}
freetds-buildlink: _BUILDLINK_USE

.endif	# FREETDS_BUILDLINK_MK
