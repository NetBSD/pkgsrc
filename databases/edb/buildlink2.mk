# $NetBSD: buildlink2.mk,v 1.3 2003/05/02 11:54:11 wiz Exp $

.if !defined(EDB_BUILDLINK2_MK)
EDB_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		edb
BUILDLINK_DEPENDS.edb?=		edb>=1.0.3nb2
BUILDLINK_PKGSRCDIR.edb?=	../../databases/edb

EVAL_PREFIX+=		BUILDLINK_PREFIX.edb=edb
BUILDLINK_PREFIX.edb_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.edb=	include/Edb.h
BUILDLINK_FILES.edb+=	lib/libedb.*

BUILDLINK_TARGETS+=	edb-buildlink

edb-buildlink: _BUILDLINK_USE

.endif	# EDB_BUILDLINK2_MK
