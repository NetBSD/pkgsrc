# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:03 jlam Exp $

.if !defined(DB_BUILDLINK2_MK)
DB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		db
BUILDLINK_DEPENDS.db?=		db>=2.7.3
BUILDLINK_PKGSRCDIR.db?=	../../databases/db

EVAL_PREFIX+=		BUILDLINK_PREFIX.db=db
BUILDLINK_PREFIX.db_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.db=	include/db2/*
BUILDLINK_FILES.db+=	lib/libdb2.*

BUILDLINK_TARGETS+=	db-buildlink

db-buildlink: _BUILDLINK_USE

.endif	# DB_BUILDLINK2_MK
