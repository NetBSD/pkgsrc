# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:22:13 jlam Exp $

.if !defined(UNIXODBC_BUILDLINK2_MK)
UNIXODBC_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		unixodbc
BUILDLINK_DEPENDS.unixodbc?=	unixodbc>=2.0.11
BUILDLINK_PKGSRCDIR.unixodbc?=	../../databases/unixodbc

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

.include "../../devel/libtool/buildlink2.mk"
.include "../../devel/pth/buildlink2.mk"

BUILDLINK_TARGETS+=	unixodbc-buildlink

unixodbc-buildlink: _BUILDLINK_USE

.endif	# UNIXODBC_BUILDLINK2_MK
