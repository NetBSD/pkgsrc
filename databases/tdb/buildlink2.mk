# $NetBSD: buildlink2.mk,v 1.1.1.1 2002/11/29 19:19:12 jmmv Exp $
#

.if !defined(TDB_BUILDLINK2_MK)
TDB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		tdb
BUILDLINK_DEPENDS.tdb?=		tdb>=1.0.6
BUILDLINK_PKGSRCDIR.tdb?=	../../databases/tdb

EVAL_PREFIX+=			BUILDLINK_PREFIX.tdb=tdb
BUILDLINK_PREFIX.tdb_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.tdb=		include/tdb.h
BUILDLINK_FILES.tdb+=		lib/libtdb.*

BUILDLINK_TARGETS+=		tdb-buildlink

tdb-buildlink: _BUILDLINK_USE

.endif	# TDB_BUILDLINK2_MK
