# $NetBSD: buildlink.mk,v 1.3 2001/07/01 22:59:14 jlam Exp $
#
# This Makefile fragment is included by packages that use tcl-postgresql.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.tcl-postgresql to the dependency
#     pattern for the version of tcl-postgresql desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(TCL_POSTGRESQL_BUILDLINK_MK)
TCL_POSTGRESQL_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.tcl-postgresql?=	tcl-postgresql>=7.0
DEPENDS+=	${BUILDLINK_DEPENDS.tcl-postgresql}:../../databases/tcl-postgresql

BUILDLINK_PREFIX.tcl-postgresql=	${LOCALBASE}
BUILDLINK_FILES.tcl-postgresql=		include/pgsql/libpgtcl.h
BUILDLINK_FILES.tcl-postgresql+=	lib/libpgtcl.*

.include "../../lang/tcl/buildlink.mk"

BUILDLINK_TARGETS.tcl-postgresql=	tcl-postgresql-buildlink
BUILDLINK_TARGETS+=			${BUILDLINK_TARGETS.tcl-postgresql}

pre-configure: ${BUILDLINK_TARGETS.tcl-postgresql}
tcl-postgresql-buildlink: _BUILDLINK_USE

.endif	# TCL_POSTGRESQL_BUILDLINK_MK
