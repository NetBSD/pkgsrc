# $NetBSD: buildlink2.mk,v 1.2 2003/05/12 14:57:41 jmc Exp $
#
# This Makefile fragment is included by packages that use dbh.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(DBH_BUILDLINK2_MK)
DBH_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			dbh
BUILDLINK_DEPENDS.dbh?=			dbh>=1.0.14
BUILDLINK_PKGSRCDIR.dbh?=		../../databases/dbh

EVAL_PREFIX+=	BUILDLINK_PREFIX.dbh=dbh
BUILDLINK_PREFIX.dbh_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.dbh+=	include/dbh.h
BUILDLINK_FILES.dbh+=	include/dbh_config.h
BUILDLINK_FILES.dbh+=	include/dbh_functions.h
BUILDLINK_FILES.dbh+=	lib/libdbh-1.0.*
BUILDLINK_FILES.dbh+=	lib/libdbh.*
BUILDLINK_FILES.dbh+=	lib/pkgconfig/dbh-1.0.pc

BUILDLINK_TARGETS+=	dbh-buildlink

dbh-buildlink: _BUILDLINK_USE

.endif	# DBH_BUILDLINK2_MK
