# $NetBSD: buildlink2.mk,v 1.1 2003/04/13 15:26:31 cjep Exp $

.if !defined(IODBC_BUILDLINK2_MK)
IODBC_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		iodbc
BUILDLINK_DEPENDS.iodbc?=	iodbc>=2.50.3
BUILDLINK_PKGSRCDIR.iodbc?=	../../databases/iodbc

EVAL_PREFIX+=		BUILDLINK_PREFIX.iodbc=iodbc
BUILDLINK_PREFIX.iodbc_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.iodbc=	include/isql.h
BUILDLINK_FILES.iodbc+=	include/isqlext.h
BUILDLINK_FILES.iodbc+=	include/isqltypes.h
BUILDLINK_FILES.iodbc+=	include/sql.h
BUILDLINK_FILES.iodbc+=	include/sqlext.h
BUILDLINK_FILES.iodbc+=	include/sqltypes.h
BUILDLINK_FILES.iodbc+=	lib/libiodbc.*

BUILDLINK_TARGETS+=	iodbc-buildlink

iodbc-buildlink: _BUILDLINK_USE

.endif	# IODBC_LIB_BUILDLINK2_MK
