# $NetBSD: buildlink.mk,v 1.1.1.1 2001/11/06 04:08:34 jlam Exp $
#
# This Makefile fragment is included by packages that use unixodbc.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.unixodbc to the dependency pattern
#     for the version of unixodbc desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(UNIXODBC_BUILDLINK_MK)
UNIXODBC_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.unixodbc?=	unixodbc>=2.0.11
DEPENDS+=	${BUILDLINK_DEPENDS.unixodbc}:../../databases/unixodbc

EVAL_PREFIX+=	BUILDLINK_PREFIX.unixodbc=unixodbc
BUILDLINK_PREFIX.unixodbc_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.unixodbc=		include/autotest.h
BUILDLINK_FILES.unixodbc+=		include/odbcinst.h
BUILDLINK_FILES.unixodbc+=		include/odbcinstext.h
BUILDLINK_FILES.unixodbc+=		include/sql.h
BUILDLINK_FILES.unixodbc+=		include/sqlext.h
BUILDLINK_FILES.unixodbc+=		include/sqltypes.h
BUILDLINK_FILES.unixodbc+=		include/sqlucode.h
BUILDLINK_FILES.unixodbc+=		include/uodbc_stats.h
BUILDLINK_FILES.unixodbc+=		lib/libboundparam.*
BUILDLINK_FILES.unixodbc+=		lib/libgtrtst.*
BUILDLINK_FILES.unixodbc+=		lib/libodbc.*
BUILDLINK_FILES.unixodbc+=		lib/libodbccr.*
BUILDLINK_FILES.unixodbc+=		lib/libodbcextras.*
BUILDLINK_FILES.unixodbc+=		lib/libodbcinst.*

.include "../../devel/libtool/buildlink.mk"
.include "../../devel/pth/buildlink.mk"

BUILDLINK_TARGETS.unixodbc=	unixodbc-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.unixodbc}

pre-configure: ${BUILDLINK_TARGETS.unixodbc}
unixodbc-buildlink: _BUILDLINK_USE

.endif	# UNIXODBC_BUILDLINK_MK
