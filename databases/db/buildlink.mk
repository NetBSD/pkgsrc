# $NetBSD: buildlink.mk,v 1.1 2001/06/19 07:37:37 jlam Exp $
#
# This Makefile fragment is included by packages that use db.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define DB_REQD to the version of db desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(DB_BUILDLINK_MK)
DB_BUILDLINK_MK=	# defined

DB_REQD?=		2.7.3
DEPENDS+=		db>=${DB_REQD}:../../databases/db

BUILDLINK_PREFIX.db=	${LOCALBASE}
BUILDLINK_FILES.db=	include/db2/*
BUILDLINK_FILES.db+=	lib/libdb2.*

BUILDLINK_TARGETS.db=	db-buildlink
BUILDLINK_TARGETS+=	${BUILDLINK_TARGETS.db}

pre-configure: ${BUILDLINK_TARGETS.db}
db-buildlink: _BUILDLINK_USE

.include "../../mk/bsd.buildlink.mk"

.endif	# DB_BUILDLINK_MK
