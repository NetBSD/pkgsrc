# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:22:11 jlam Exp $

.if !defined(SQLITE_BUILDLINK2_MK)
SQLITE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		sqlite
BUILDLINK_DEPENDS.sqlite?=	sqlite>=2.0.5
BUILDLINK_PKGSRCDIR.sqlite?=	../../databases/sqlite

EVAL_PREFIX+=				BUILDLINK_PREFIX.sqlite=sqlite
BUILDLINK_PREFIX.sqlite_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.sqlite=			include/sqlite.h
BUILDLINK_FILES.sqlite+=		lib/libsqlite.*

BUILDLINK_TARGETS+=	sqlite-buildlink

sqlite-buildlink: _BUILDLINK_USE

.endif	# SQLITE_BUILDLINK2_MK
