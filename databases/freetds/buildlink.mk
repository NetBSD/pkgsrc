# $NetBSD: buildlink.mk,v 1.6 2001/07/02 04:40:37 jlam Exp $
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

BUILDLINK_DEPENDS.freetds?=	freetds>=0.50
DEPENDS+=	${BUILDLINK_DEPENDS.freetds}:../../databases/freetds

BUILDLINK_PREFIX.freetds=	${LOCALBASE}
BUILDLINK_FILES.freetds=	freetds/include/*
BUILDLINK_FILES.freetds+=	freetds/lib/*
BUILDLINK_FILES.freetds+=	freetds/interfaces

REPLACE_BUILDLINK_SED+=	\
	-e "s|-I${BUILDLINK_DIR}/freetds/|-I${LOCALBASE}/freetds/|g"	\
	-e "s|-L${BUILDLINK_DIR}/freetds/|-L${LOCALBASE}/freetds/|g"
BUILDLINK_CONFIG_WRAPPER_SED+=	\
	-e "s|-I${LOCALBASE}/freetds/|-I${BUILDLINK_DIR}/freetds/|g"	\
	-e "s|-L${LOCALBASE}/freetds/|-L${BUILDLINK_DIR}/freetds/|g"

BUILDLINK_TARGETS.freetds=	freetds-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.freetds}

pre-configure: ${BUILDLINK_TARGETS.freetds}
freetds-buildlink: _BUILDLINK_USE

.endif	# FREETDS_BUILDLINK_MK
