# $NetBSD: buildlink.mk,v 1.1 2001/06/21 21:41:35 jlam Exp $
#
# This Makefile fragment is included by packages that use tcl-postgresql.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define TCL_POSTGRESQL_REQD to the version of tcl-postgresql
#     desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(TCL_POSTGRESQL_BUILDLINK_MK)
TCL_POSTGRESQL_BUILDLINK_MK=	# defined

TCL_POSTGRESQL_REQD=	7.0
DEPENDS+=	tcl-postgresql>=${TCL_POSTGRESQL_REQD}:../../databases/tcl-postgresql

BUILDLINK_PREFIX.tcl-postgresql=	${LOCALBASE}
BUILDLINK_FILES.tcl-postgresql=		include/pgsql/libpgtcl.h
BUILDLINK_FILES.tcl-postgresql+=	lib/libpgtcl.*

.include "../../lang/tcl/buildlink.mk"

BUILDLINK_TARGETS.tcl-postgresql=	tcl-postgresql-buildlink
BUILDLINK_TARGETS+=			${BUILDLINK_TARGETS.tcl-postgresql}

pre-configure: ${BUILDLINK_TARGETS.tcl-postgresql}
tcl-postgresql-buildlink: _BUILDLINK_USE

.include "../../mk/bsd.buildlink.mk"

.endif	# TCL_POSTGRESQL_BUILDLINK_MK
